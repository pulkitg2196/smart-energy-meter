from twilio.rest import Client
from time import sleep
import serial

ser = serial.Serial('/dev/ttyACM0',9600)
account_sid = 'ACf014e3c671719f340709b6fa0019dbc8' # Found on Twilio Console Dashboard
auth_token = 'c3ab3fd97d5f936e3aa65f5fb761c659' # Found on Twilio Console Dashboard

#while 1:
a = ser.readline()
b = ser.readline()
c = a.decode('utf-8')
d = b.decode('utf-8')
#r = 45
#myPhone = '+919041143113' # Phone number you used to verify your Twilio account
#TwilioNumber = '19163185349' # Phone number given to you by Twilio

client = Client(account_sid, auth_token)

client.messages.create(to='+919041143113', from_='+19163185349',
  	body='Your units consumed are : '+ str(c)+'\nYour bill is : '+str(d))
	

