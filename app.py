import getSubmissions
import user
import config

from flask import Flask,render_template ,request ,redirect ,url_for, jsonify

app = Flask(__name__)


@app.route('/')
def getRanklist():
	ranklist = user.getScoreBoard()
	problems = user.getProblems()
	return render_template('index.html',ranklist=ranklist,problems=problems,contestName=config.contestName)