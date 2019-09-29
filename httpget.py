import requests
import time
while (1):
    try:
        requests.get("http://192.168.137.3/off",timeout=0.1)
    except requests.exceptions.ReadTimeout: 
        pass
    time.sleep(0.6)
    try:
        requests.get("http://192.168.137.3/on",timeout=0.1)
    except requests.exceptions.ReadTimeout: 
        pass
    time.sleep(0.6)

    # r = requests.get("http://192.168.137.27/off")
    # time.sleep(0.25)
    # r = requests.get("http://192.168.137.27/on")
    # time.sleep(0.25)
    