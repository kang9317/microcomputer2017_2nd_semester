import serial
import time
from omxplayer import OMXPlayer
from threading import Thread
con = serial.Serial('/dev/ttyAMA0', 9600, timeout=0.05)

#, write_timeout = 20
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

b_code = [b'0001', b'0011', b'0010', b'0100' ,b'0101', b'1000', b'1001', b'1010', b'1011', b'1100', b'1101', b'1110' ,b'1111']
p_name = ['./save/manual_woman.mp3','./save/auto_woman.mp3','./save/manual/power.mp3','./save/manual/manual.mp3','./save/auto.mp3','./save/manual/straight_back.mp3','./save/manual/straight_go.mp3','./save/manual/left_go.mp3','./save/manual/right_go.mp3','./save/manual/sleft_go.mp3','./save/manual/sright_go.mp3','./save/manual/left_rotation.mp3','./save/manual/right_rotation.mp3']

def play_mp3(p_name_n):
    try:
        player = OMXPlayer("{0}".format(p_name_n))    
        player.play()
        #player.quit()
        #con.write(b'comp')
        #print("send")
        #time.sleep(0.625)
        #con.write(b'0000')
        print("init")
        #time.sleep(0.625)
    except:
        pass
def connect_atmega128(res1,b_code_n, p_name_n):
    try:
        #time.sleep(1)
        if res1 == b_code_n:
            th = Thread(target=play_mp3(p_name_n))
            th.demon = True
            th.start()
            #play_mp3(p_name_n)
    except KeyboardInterrupt:
        con.close()
        
def main():
    while(True):
        res1 = con.readline()
        print(res1)
        if res1 == b_code[0]:
            connect_atmega128(res1, b_code[0],p_name[0])
        elif res1 == b_code[1]:
            connect_atmega128(res1, b_code[1],p_name[1])
        elif res1 == b_code[2]:
            connect_atmega128(res1, b_code[2],p_name[2])
        elif res1 == b_code[3]:
            connect_atmega128(res1, b_code[3],p_name[3])
        elif res1 == b_code[4]:
            connect_atmega128(res1, b_code[4],p_name[4])
        elif res1 == b_code[5]:
            connect_atmega128(res1, b_code[5],p_name[5])
        elif res1 == b_code[6]:
            connect_atmega128(res1, b_code[6],p_name[6])
        elif res1 == b_code[7]:
            connect_atmega128(res1, b_code[7],p_name[7])
        elif res1 == b_code[8]:
            connect_atmega128(res1, b_code[8],p_name[8])
        elif res1 == b_code[9]:
            connect_atmega128(res1, b_code[9],p_name[9])
        elif res1 == b_code[10]:
            connect_atmega128(res1, b_code[10],p_name[10])
        elif res1 == b_code[11]:
            connect_atmega128(res1, b_code[11],p_name[11])
        elif res1 == b_code[12]:
            connect_atmega128(res1, b_code[12],p_name[12])

main()
