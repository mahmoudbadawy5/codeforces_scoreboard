# Local imports
import config
import api
import processSubmissions


# Global imports 
import time, os
import random
import hashlib
import urllib.request
import json

# Global Variables
proccessedSubmissions = set()

def updateSubmissions():
	contestCount = 1
	for contest in config.contestIds:
		data = {"contestId": contest}
		submissions = api.callApi('contest.status',data)
		if submissions is None:
			return
		for submission in submissions['result']:
			subID=submission['id']
			if subID in proccessedSubmissions:
				continue
			print(processSubmissions.processSubmission(contestCount,submission))
			proccessedSubmissions.add(subID)
		contestCount = contestCount+1
