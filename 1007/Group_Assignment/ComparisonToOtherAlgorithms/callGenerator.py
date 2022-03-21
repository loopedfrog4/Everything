import requests
import os

URL = "https://my.api.mockaroo.com/test.json?key=95b20f00"

r = requests.get(url = URL)
cleaned = r.text.split('\n', 1)[1]

final = cleaned.replace(",", " ")

f = open("dummy.txt", "w")
f.write(final)

f = open('dummy.txt', 'r')
print(f.read())
f.close()
