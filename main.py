from machine import Pin
from time import sleep
from ir_rx.print_error import print_error
from ir_rx.nec import NEC_8
import time
 

pin_ir = Pin(0, Pin.IN)


pin_r = Pin(29, Pin.OUT)
pin_g = Pin(26, Pin.OUT)
pin_b = Pin(27, Pin.OUT)
pin_y = Pin(28, Pin.OUT)
pin_w = Pin(14, Pin.OUT)

def toggle_leds(r, g, b, y, w):
    pin_r.value(r)
    pin_g.value(g)
    pin_b.value(b)
    pin_y.value(y)
    pin_w.value(w)


ledsActive = 0
timeMs = 60

previousMillis = 0



# Define the function to increase timeMs
def increase_time():
    global timeMs
    if timeMs < 300:
        timeMs += 10

# Define the function to decrease timeMs
def decrease_time():
    global timeMs
    if timeMs > 20:
        timeMs -= 10


animation1step = 0
def animation1():
    global animation1step,previousMillis
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis

        if animation1step == 0:
            toggle_leds(1, 0, 0, 0, 0)
        elif animation1step == 1:
            toggle_leds(0, 1, 0, 0, 0)
        elif animation1step == 2:
            toggle_leds(0, 0, 1, 0, 0)
        elif animation1step == 3:
            toggle_leds(0, 0, 0, 1, 0)
        elif animation1step == 4:
            toggle_leds(0, 0, 0, 0, 1)
        elif animation1step == 5:
            toggle_leds(0, 0, 0, 1, 0)
        elif animation1step == 6:
            toggle_leds(0, 0, 1, 0, 0)
        elif animation1step == 7:
            toggle_leds(0, 1, 0, 0, 0)
        
        
        animation1step += 1
        if animation1step > 7:
            animation1step = 0

animation2step = 0

def animation2():
    global animation2step,previousMillis
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis
        
        if animation2step == 0:
            toggle_leds(1, 0, 0, 0, 1)
        elif animation2step == 1 or animation2step == 3:
            toggle_leds(0, 0, 0, 0, 0)
        elif animation2step == 2:
            toggle_leds(0, 1, 0, 1, 0)
        
        animation2step += 1
        if animation2step > 3:
            animation2step = 0

animation3step = 0
def animation3():
    global animation3step,previousMillis
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis
        if animation3step == 0:
            toggle_leds(1, 0, 0, 1, 0)
        elif animation3step == 1 or animation3step == 3:
            toggle_leds(0, 0, 0, 0, 0)
        elif animation3step == 2:
            toggle_leds(0, 1, 0, 0, 1)
        
        animation3step += 1
        if animation3step > 3:
            animation3step = 0

animation4step = 0
def animation4():
    global animation4step,previousMillis
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis
        
        if animation4step == 0:
            toggle_leds(0, 0, 1, 0, 0)
        elif animation4step == 1:
            toggle_leds(0, 1, 0, 1, 0)
        elif animation4step == 2 or animation4step == 4:
            toggle_leds(0, 0, 0, 0, 0)
        elif animation4step == 3:
            toggle_leds(1, 0, 0, 0, 1)
        
        animation4step += 1
        if animation4step > 4:
            animation4step = 0

animation5step = 0
def animation5():
    global animation5step,previousMillis
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis
        
        
        if animation5step == 0 :
            for i in range(3):
                toggle_leds(1, 0, 0, 1, 0)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)
        elif animation5step == 1:
            for i in range(3):
                toggle_leds(0, 1, 0, 0, 1)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)

        animation5step += 1
        if animation5step > 1:
            animation5step = 0


animation6step = 0
def animation6():
    global animation6step,previousMillis
    
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis
        
        
        if animation6step == 0 :
            for i in range(3):
                toggle_leds(0, 1, 0, 1, 0)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)
        elif animation6step == 1:
            for i in range(3):
                toggle_leds(1, 0, 0, 0, 1)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)

        animation6step += 1
        if animation6step > 1:
            animation6step = 0

animation7step = 0
def animation7():
    global animation7step,previousMillis
    
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis
        
        
        if animation7step == 0 :
            for i in range(3):
                toggle_leds(0, 1, 0, 1, 0)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)
        elif animation7step == 1:
            for i in range(3):
                toggle_leds(1, 0, 0, 0, 1)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)
        elif animation7step == 2:
            for i in range(3):
                toggle_leds(0, 0, 1, 0, 0)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)

        animation7step += 1
        if animation7step > 2:
            animation7step = 0
            
animation8step = 0
def animation8():
    global animation8step,previousMillis
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis
        
        
        if animation8step == 0 :
            for i in range(3):
                toggle_leds(1, 0, 1, 1, 0)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)
        elif animation8step == 1:
            for i in range(3):
                toggle_leds(0, 1, 1, 0, 1)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)

        animation8step += 1
        if animation8step > 1:
            animation8step = 0

animation9step = 0
def animation9():
    global animation9step,previousMillis
    
    
    
    currentMillis = time.ticks_ms()

    if currentMillis - previousMillis >= timeMs:
        previousMillis = currentMillis
        
        
        if animation9step == 0 :
            for i in range(3):
                toggle_leds(0, 1, 1, 1, 0)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)
        elif animation9step == 1:
            for i in range(3):
                toggle_leds(1, 0, 1, 0, 1)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)

        animation9step += 1
        if animation9step > 1:
            animation9step = 0

def decodeKeyValue(data):
    if data == 0x45:
        return "1"
    if data == 0x46:
        return "2"
    if data == 0x47:
        return "3"
    if data == 0x44:
        return "4"
    if data == 0x40:
        return "5"
    if data == 0x43:
        return "6"
    if data == 0x7:
        return "7"
    if data == 0x15:
        return "8"
    if data == 0x09:
        return "9"
    if data == 0x16:
        return "*"
    if data == 0x0D:
        return "#"
    if data == 0x18:
        return "UP"
    if data == 0x08:
        return "LEFT"
    if data == 0x5A:
        return "RIGHT"
    if data == 0x52:
        return "DOWN"
    if data == 0x1C:
        return "OK"
    if data == 0x19:
        return "0"
    
    return "ERROR"




def callback(data, addr, ctrl):
    global ledsActive,animationIndex
    if data < 0:  # NEC protocol sends repeat codes.
        pass
    else:
        decodedDatas = decodeKeyValue(data)
        
        if decodedDatas == "1":
            animationIndex = 1
        if decodedDatas == "2":
            animationIndex = 2
        if decodedDatas == "3":
            animationIndex = 3
        if decodedDatas == "4":
            animationIndex = 4
        if decodedDatas == "5":
            animationIndex = 5
        if decodedDatas == "6":
            animationIndex = 6
        if decodedDatas == "7":
            animationIndex = 7
        if decodedDatas == "8":
            animationIndex = 8
        if decodedDatas == "9":
            animationIndex = 9
        if decodedDatas == "0":
            toggle_leds(1, 1, 1, 1, 1)
            sleep(timeMs / 1000 / 2)
        if decodedDatas == "*":
            for i in range(3):
                toggle_leds(1, 1, 1, 1, 1)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)
        if decodedDatas == "#":
            for i in range(3):
                toggle_leds(1, 0, 1, 1, 0)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000 / 2)
            for i in range(3):
                toggle_leds(0, 1, 1, 0, 1)
                sleep(timeMs / 1000)
                toggle_leds(0, 0, 0, 0, 0)
                sleep(timeMs / 1000)
            
        if decodedDatas == "LEFT":
            decrease_time()
        if decodedDatas == "RIGHT":
            increase_time()
        
        if decodedDatas == "OK":
            if ledsActive:
                ledsActive = 0
            else:
                ledsActive = 1
            
            

ir = NEC_8(pin_ir, callback)  # IR alıcısı için receiver oluştur
ir.error_function(print_error)  # Hata ayıklama için fonksiyonu tanımla


animations = {
    1: animation1,
    2: animation2,
    3: animation3,
    4: animation4,
    5: animation5,
    6: animation6,
    7: animation7,
    8: animation8,
    9: animation9,
    # Diğer animasyonlar buraya eklenebilir
}
animationIndex = 5

try:
    while True:
        if ledsActive == 0:
            toggle_leds(0, 0, 0, 0, 0)
            time.sleep(0.1)
        
        else:
            animations.get(animationIndex, lambda: None)()
            
            
except KeyboardInterrupt:
    ir.close()
    toggle_leds(0, 0, 0, 0, 0)

