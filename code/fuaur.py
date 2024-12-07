import requests
import time
import random

url = 'url'

while True:
    try:
        response = requests.get(url)
        # print(response.text)
        print(f"Page refreshed at {time.ctime()}")
        time.sleep(random.uniform(1, 3))
    except Exception as e:
        print(f"An error occurred: {e}")
        break
