import getSubmissions
import user
import config

from flask import Flask,render_template ,request ,redirect ,url_for, jsonify
from threading import Timer, Event 
import os

app = Flask(__name__)

'''def updateEveryInterval(): 
	if not done.is_set():
		#print("Started")
		getSubmissions.updateSubmissions()
		Timer(config.updateInterval, updateEveryInterval).start() 


done = Event() 
Timer(0, updateEveryInterval).start() 
'''

# Preparing paths needed
folders = ['data','logs']

for folder in folders:
	if not os.path.exists(folder):
		os.mkdir(folder)

@app.route('/')
def getRanklist():
	ranklist = user.getScoreBoard()
	problems = user.getProblems()
	prSubs = getSubmissions.processedSubmissionsCount
	totSubs = getSubmissions.totalSubmissions
	#print(ranklist)
	return render_template('index.html',ranklist=ranklist,problems=problems,
		contestName=config.contestName,percent=100.0*max(prSubs,1)/max(totSubs,1))

@app.route('/details/<user_name>')
def getUser(user_name):
	data=user.getUser(user_name)
	problems = []
	for problem in data.keys():
		if problem != 'name':
			problems.append(problem)
	problems = sorted(problems)
	return render_template('details.html',data=data,problems=problems)