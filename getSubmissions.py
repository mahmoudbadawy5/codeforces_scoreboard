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
processedSubmissions = set()

inited = False
locked = False
totalSubmissions = 0
processedSubmissionsCount = 0
lastFetched = -1

def init():
	global inited
	if inited:
		return
	if not os.path.isfile('logs/processedSubmissions.txt'):
		return
	f = open('logs/processedSubmissions.txt','r')
	for line in f:
		try:
			x=int(line)
			processedSubmissions.add(x)
		except:
			pass
	inited=True

def save():
	global processedSubmissions
	f = open('logs/processedSubmissions.txt','w')
	for sub in processedSubmissions:
		f.write(str(sub)+'\n')

def addToFile(submission):
	f = open('logs/processedSubmissions.txt','a')
	f.write(submission+'\n')

def updateSubmissions():
	global locked , processedSubmissions, processedSubmissionsCount, totalSubmissions
	global lastFetched
	if locked:
		return
	init()
	locked = True
	totalSubmissions = 0
	processedSubmissionsCount = 0
	contestCount = 1
	for contest in config.contestIds:
		data = {"contestId": contest}
		submissions = api.callApi('contest.status',data)
		curTime = int(time.time())
		if submissions is None:
			continue
		totalSubmissions = totalSubmissions + len(submissions['result'])
		for submission in submissions['result']:
			processedSubmissionsCount = processedSubmissionsCount+1
			print(str(processedSubmissionsCount)+"/"+str(totalSubmissions))
			subID=submission['id']
			if subID in processedSubmissions or not 'verdict' in submission.keys():
				continue
			#if submission['author']['participantType'] != 'CONTESTANT':
			#	continue
			if submission['problem']['index'] == 'A' or submission['problem']['index']=='B':
				continue
			processSubmissions.processSubmission(contestCount,submission)
			processedSubmissions.add(subID)
			addToFile(subID)
		contestCount = contestCount+1
	save()
	locked = False