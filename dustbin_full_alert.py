from boltiot import Sms, Bolt
import json, time

mybolt = Bolt(conf.API_KEY, conf.DEVICE_ID)
sms = Sms(conf.SID, conf.AUTH_TOKEN, conf.TO_NUMBER, conf.FROM_NUMBER)
garbage_limit = 10
response = mybolt.serialRead('13')
print(response)


while True:
    print ("Reading sensor value")
    response = mybolt.serialRead('13')
    data = json.loads(response)
    print("Garbage value is: " + str(data['value']))
    try:
        garbage_value = int(data['value'].rstrip())
        if garbage_value < garbage_limit or garbage_value == 357:
            print("Making request to Twilio to send a SMS")
            response = sms.send_sms("Hello I'm full, please clean me")
    except Exception as e:
        print ("Error occurred: Below are the details")
        print (e)
    time.sleep(20)
