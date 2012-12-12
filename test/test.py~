#!/usr/bin/python
import thread 
import sys
import mosquitto
import time
from struct import *

##def controll():
##    while True:
##        
##        lw = int(raw_input('lw:'))
##        rw = int(raw_input('rw='))
##        do_stuff(lw,rw)



teren =[ [ 0 for i in range(13) ] for j in range(13) ]
def thread1():
    client = mosquitto.Mosquitto("Feliz Navidad1")
    client.connect("localhost")#192.168.1.72   
    def on_message(msgmosq, obj, msg):
            global teren
            mesaj = unpack('iiiii', msg.payload)
            print mesaj
            print "    "
            for i in range(0,4):
                teren[mesaj[0]-1][i] = mesaj[i]
            print teren
                    
            #id,x,y,grad,t = unpack('iiiii', msg.payload)
            #print "id robot: ",id
            #print "x: ",x
            #print "y: ",y
            #print "grad: ",grad
            #print "t: ",t
            #if(x== 1055):
            #       do_stuff(255,255)

    client.subscribe("coords", 2)
    client.on_message = on_message
    while client.loop() == 0:
        pass

def salut():
    print "Salut din afara 2"

def thread2():
    client2 = mosquitto.Mosquitto("Feliz Navidad2")
    client2.connect("localhost")#192.168.1.72
    ok=0
    salut()
    while ok==0:
        global teren
        if teren[4][0] == 5:
            print "l-am gasit cu thread 2  "
            ok=1
            
            
    def do_stuff(lw, rw,id):
        global client2
        msg = pack('iii', lw, rw, 0)
        print msg
        client2.publish(id, msg)

try:
   thread.start_new_thread( thread1, () )
   thread.start_new_thread( thread2, () )
except:
   print "Error: unable to start thread"

while 1:
   pass

