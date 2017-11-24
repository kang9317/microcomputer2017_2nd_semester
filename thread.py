from threading import Thread
from time import sleep
 
def printHello():
    while True:
        print("hello")
        sleep(3)
def printHello2():
    while True:
        print("hello2")
        sleep(5)
 
def main():
    th = Thread(target=printHello)
    th.demon = True
    th.start()
    th2 = Thread(target=printHello2)
    th2.demon = True
    th2.start()
    for i in range(1,100000):
        print(i)
        sleep(1)
if __name__ == '__main__':
    main()
