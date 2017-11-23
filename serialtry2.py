import serial
import time
import vlc

import pygame

con = serial.Serial('/dev/ttyAMA0', 19200, timeout=0.057, write_timeout = 20)

####comment binary
#x 0000 default
#0 0001 sr-sensor
#1 0010 spray
#2 0011 power on
#3 0100 manual mode on
#4 0101 manual mode off
#5 1000 back
#6 1001 straight_go
#7 1010 left
#8 1011 right
#9 1100 sleft
#10 1101 sright
#11 1110 180'left
#12 1111 180'right

b_code = [b'0001', b'0010', b'0011', b'0100' ,b'0101', b'1000', b'1001', b'1010', b'1011', b'1100', b'1101', b'1110' ,b'1111']
p_name = ['./save/beep.mp3','./save/spray.mp3','./save/manual/power.mp3','./save/manual/manual.mp3','./save/auto.mp3','./save/manual/straight_back.mp3','./save/manual/straight_go.mp3','./save/manual/left_go.mp3','./save/manual/right_go.mp3','./save/manual/sleft_go.mp3','./save/manual/sright_go.mp3','./save/manual/left_rotation.mp3','./save/manual/right_rotation.mp3']


def play_beep(p_name_n):
    pygame.mixer.init()
    pygame.mixer.music.load("{0}".format(p_name_n))
    pygame.mixer.music.play()
    con.write(b'comp')
    print("send")
    time.sleep(0.0625)
    con.write(b'0000')
    print("init")
    time.sleep(0.0625)
    while pygame.mixer.music.get_busy() == True: 
        continue


def play_mp3(p_name_n):
    p = vlc.MediaPlayer("{0}".format(p_name_n))
    p.stop()
    p.play()
    con.write(b'comp')
    print("send")
    time.sleep(0.0625)
    con.write(b'0000')
    print("init")
    time.sleep(0.0625)

def connect_atmega128(b_code_n, p_name_n):
    try:
        time.sleep(1)
        while 1:
            #res1 = con.readline()
            #print(res1)
            if (len(con.readline()) == 4):
                res = con.readline()
                print(res)
                valid = 0
                if(res == b_code_n):
                    #play_mp3(p_name_n)
                    play_beep(p_name_n)
    except KeyboardInterrupt:
        con.close()
        
def main():
    while(True):
        for i in range(0,13):
            connect_atmega128(b_code[i],p_name[i])

main()
