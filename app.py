import getSubmissions
import user
import config

from flask import Flask,render_template ,request ,redirect ,url_for, jsonify
from threading import Timer, Event 

app = Flask(__name__)

def updateEveryInterval(): 
	if not done.is_set():
		#print("Started")
		getSubmissions.updateSubmissions()
		Timer(config.updateInterval, updateEveryInterval).start() 

done = Event() 
Timer(0, updateEveryInterval).start() 

@app.route('/')
def getRanklist():
	ranklist = user.getScoreBoard()
	problems = user.getProblems()
	prSubs = getSubmissions.processedSubmissionsCount
	totSubs = getSubmissions.totalSubmissions
	#print(ranklist)
	return render_template('index.html',ranklist=ranklist,problems=problems,
		contestName=config.contestName,percent=100.0*max(prSubs,1)/max(totSubs,1))