# Edge Impulse - OpenMV Object Detection Example

import sensor, image, time, os, tf, math, uos, gc, pyb

sensor.reset()                         # Reset and initialize the sensor.
sensor.set_pixformat(sensor.GRAYSCALE)    # Set pixel format to RGB565 (or GRAYSCALE)
sensor.set_framesize(sensor.QVGA)      # Set frame size to QVGA (320x240)
sensor.set_windowing((240, 240))       # Set 240x240 window.
#sensor.skip_frames(time=5000)          # Let the camera adjust.
time.sleep_ms(1000)
net = None
labels = None
min_confidence = 0.6

try:
    # load the model, alloc the model file on the heap if we have at least 64K free after loading
    net = tf.load("trained.tflite", load_to_fb=uos.stat('trained.tflite')[6] > (gc.mem_free() - (64*1024)))
except Exception as e:
    raise Exception('Failed to load "trained.tflite", did you copy the .tflite and labels.txt file onto the mass-storage device? (' + str(e) + ')')

try:
    labels = [line.rstrip('\n') for line in open("labels.txt")]
except Exception as e:
    raise Exception('Failed to load "labels.txt", did you copy the .tflite and labels.txt file onto the mass-storage device? (' + str(e) + ')')
def takeSecond(ele):
    return ele[1]
def DelRep(a):
    res=[]
    [res.append(x) for x in a if x not in res]
    return res
def ObjGet(a):
    res=[]
    for i in a:
        res.append(i[0])
    return res
def DelRed(aa):
    length=[0 for i in range(len(aa)-1)]
    ii=0
    for i in length:
        if aa[ii][1]==aa[ii+1][1]:
            if aa[ii][2]>aa[ii+1][2]:
                aa[ii+1]=[0,0,0]
            else:
                aa[ii]=[0,0,0]
        ii=ii+1
    a=[]
    for i in aa:
        if not i==[0,0,0]:
            a.append(i)
    return a
colors = [ # Add more colors if you are detecting more than 7 types of classes at once.
    (255,   0,   0),
    (  0, 255,   0),
    (255, 255,   0),
    (  0,   0, 255),
    (255,   0, 255),
    (  0, 255, 255),
    (255, 255, 255),
    (  0,   0, 255),
    (255,   0, 255),
    (  0, 255, 255),
    (255, 255, 255),
]
p1_out = pyb.Pin('P1',pyb.Pin.OUT_PP)
p1_out.high()
P7_Out = pyb.Pin('P7',pyb.Pin.OUT_PP)#P7返回运动状态值state_car，1为继续运行
P7_Out.low()
P6_Out = pyb.Pin('P6',pyb.Pin.OUT_PP)#P6返回检测状态值state_num，1为检测到数字
P6_Out.low()

finish=0
time.sleep_ms(2000)
clock = time.clock()
while(True):#第一次循环检测初始数字
    clock.tick()
    P6_Out.low()
    img = sensor.snapshot()
    a1=[]
    temp_arr=[]
    temp_obj1=[]
    obj1=[]
    # detect() returns all objects found in the image (splitted out per class already)
    # we skip class index 0, as that is the background, and then draw circles of the center
    # of our objects

    for i, detection_list in enumerate(net.detect(img, thresholds=[(math.ceil(min_confidence * 255), 255)])):
        #if (i == 0): continue # background class
        #if (len(detection_list) == 0): continue # no detections for this class?
        #temp=labels[i]

        if (i == 0): continue # background class
        if (len(detection_list) == 0): continue # no detections for this class?
        temp_arr=[labels[i],detection_list[0].x(),detection_list[0].output()]#获取位数和x位置
        a1.append(temp_arr)
        print('a1?',a1)
    if not a1==[[]]:
        a1=DelRep(a1)#删除重复值
        a1.sort(key = takeSecond)#按x位置排序
        a1=DelRed(a1)#删除冗杂值
        print('a1??',a1)
    temp_obj1=ObjGet(a1)
    print('第一次检测第一个样本为',temp_obj1)#返回检测结果

    if not temp_obj1==[]:#有数值则再判断一次
        b1=[]
        temp_arr=[]
        time.sleep_ms(500)
        sensor.skip_frames(time=500)#消抖
        img = sensor.snapshot()
        for i, detection_list in enumerate(net.detect(img, thresholds=[(math.ceil(min_confidence * 255), 255)])):
            if (i == 0): continue # background class
            if (len(detection_list) == 0): continue # no detections for this class?
            temp_arr=[labels[i],detection_list[0].x(),detection_list[0].output()]#i-1为正确数字值，改为labels[i]则为字符型变量
            b1.append(temp_arr)
        print('b1?',b1)
        if not b1==[[]]:
            b1=DelRep(b1)#删除重复值
            b1.sort(key = takeSecond)
            b1=DelRed(b1)#删除冗杂值
        obj1=ObjGet(b1)
        print('第一次检测第二个样本为',obj1)
        if (temp_obj1==obj1):
            finish=1
            P6_Out.high()#反映第一次检测完毕
            p1_out.low()#给指示灯
            break
            #else :
                #break
                #num1_temp=0
        if finish==1:
            break
    print(clock.fps(), "fps_1", end="\n\n")
print('the first num found！！',obj1)
time.sleep_ms(500)
p1_out.high()
P6_Out.low()
time.sleep_ms(6000)

finish=0
print('###################################')
while(True):
    clock.tick()
    P6_Out.low()
    P7_Out.low()
    time.sleep_ms(500)
    sensor.skip_frames(time=500)#消抖
    img = sensor.snapshot()
    temp_arr=[]
    a2=[]
    temp_arr=[]
    temp_obj2=[]
    obj2=[]
    # detect() returns all objects found in the image (splitted out per class already)
    # we skip class index 0, as that is the background, and then draw circles of the center
    # of our objects

    for i, detection_list in enumerate(net.detect(img, thresholds=[(math.ceil(min_confidence * 255), 255)])):
        if (i == 0): continue # background class
        if (len(detection_list) == 0): continue # no detections for this class?
        temp_arr=[labels[i],detection_list[0].x(),detection_list[0].output()]#获取位数和x位置
        a2.append(temp_arr)
    if not a2==[[]]:
        a2=DelRep(a2)#删除重复值
        a2.sort(key = takeSecond)#按x位置排序
        a2=DelRed(a2)#删除冗杂值
    temp_obj2=ObjGet(a2)
    print('第二次检测第一个样本为',temp_obj2)

    if not temp_obj2==[]:#有数值则再判断一次
        b2=[]
        temp_arr=[]
        time.sleep_ms(500)
        sensor.skip_frames(time=500)#消抖
        img = sensor.snapshot()
        for i, detection_list in enumerate(net.detect(img, thresholds=[(math.ceil(min_confidence * 255), 255)])):
            if (i == 0): continue # background class
            if (len(detection_list) == 0): continue # no detections for this class?
            temp_arr=[labels[i],detection_list[0].x(),detection_list[0].output()]#i-1为正确数字值，改为labels[i]则为字符型变量
            b2.append(temp_arr)
        if not b2==[[]]:
            b2=DelRep(b2)#删除重复值
            b2.sort(key = takeSecond)
            b2=DelRed(b2)#删除冗杂值
        obj2=ObjGet(b2)
        print('第二次检测第二个样本为',obj2)
        if (temp_obj2==obj2):
            if (obj1==obj2):#对上了
                P7_Out.high()
                P6_Out.high()
                p1_out.low()
                finish=1
                time.sleep_ms(300)
                #break
            else :
                P7_Out.low()
                P6_Out.high()
                time.sleep_ms(100)
                P6_Out.low()
                P7_Out.low()
                time.sleep_ms(600)
                #break
        #else :
            #break
        if finish==1:
            break

    print(clock.fps(), "fps", end="\n\n")
print("done")
