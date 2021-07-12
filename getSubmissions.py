# Local imports
import config
import processSubmissions


# Global imports 
import time, os
import random
import hashlib
import urllib.request
import json

# Global Variables
proccessedSubmissions = set()

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



def updateSubmissions():
	contestCount = 1
	for contest in config.contestIds:
		data = {"contestId": contest}
		req = getRequest("contest.status",data)
		response = urllib.request.urlopen(req).read()
		submissions = json.loads(response)
		if submissions['status'] != u'OK':
			return
		for submission in submissions['result']:
			subID=submission['id']
			if subID in proccessedSubmissions:
				continue
			print(processSubmissions.processSubmission(contestCount,submission))
			proccessedSubmissions.add(subID)
			break
		contestCount = contestCount+1
