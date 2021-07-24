# Local imports
import config


# Global imports 
import time, os
import random
import hashlib
import urllib.request
import json


def getRequest(method,data):
	rnd=random.randint(10**5,10**6-1);
	data["time"] = int(time.time())
	data["apiKey"]= config.apiKey
	params=""
	isFirst=True
	keys = data.keys()
	keys = sorted(keys)
	for key in keys:
		if(isFirst == False):
			params=params+"&"
		isFirst=False
		params=params+str(key)+"="+str(data[key])
	sigData=str(rnd)+"/"+method+"?"+params+"#"+config.apiSecret
	sigData=hashlib.sha512(sigData.encode('utf-8')).hexdigest()
	return "https://codeforces.com/api/"+method+"?"+params+"&apiSig="+str(rnd)+sigData

def callApi(method,data):
	req = getRequest(method,data)
	try:
		response = urllib.request.urlopen(req).read()
	except:
		print('Failed to connect to codeforces API')
		return None
	result = json.loads(response)
	if result['status'] != u'OK':
		return None
	return result