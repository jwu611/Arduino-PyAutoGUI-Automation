import serial 
import time #Required to use delay functions
import pyautogui

ArduinoSerial = serial.Serial('com3',9600) #Create Serial port object called arduinoSerialData
time.sleep(2) #wait for 2 seconds for the communication to get established

while 1:
    incoming = str (ArduinoSerial.readline())
    print(incoming)

    if 'Play/Pause' in incoming:    
        pyautogui.press('space')

    if 'VolUp' in incoming:
        pyautogui.press('up')
        pyautogui.press('up')

    if 'VolDown' in incoming:
        pyautogui.press('down')
        pyautogui.press('down')

    time.sleep(1)
        
        
