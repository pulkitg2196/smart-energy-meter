import serial
import time
ser = serial.Serial('/dev/ttyACM0',9600)


while 1:
	a = ser.readline()
	b = ser.readline()
	print(a.decode('utf-8'))
	print(b.decode('utf-8'))
