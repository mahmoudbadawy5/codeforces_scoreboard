import problem
import config
import api

import os.path
import json

users = {}
scores = {}
problems = set()
scoreboardCache = []
changed = True
inited = False

def init():
	global inited, users, scores, problems
	if inited:
		return
	if os.path.isfile('data/users.txt'):
		file = open('data/users.txt','r')
		for line in file:
			data = line.split('|')
			if len(data)<4:
				continue
			users[data[1].strip()] = data[3].strip()
			scores[data[1].strip()] = {}
	if os.path.isfile('logs/userData.txt'):
		scores=json.load(open('logs/userData.txt'))
	curContestId = 1
	'''for contest in config.contestIds:
		data = {"contestId": contest}
		curProblems = api.callApi('contest.standings',data)
		if curProblems == None:
			continue
		for problem in curProblems['result']['problems']:
			problems.add(str(curContestId)+problem['index'])
		curContestId = curContestId+1
	'''
	problems = ['1A','1B','1C','2A','2B','2C']
	inited = True

def getActualName(user):
	user = user.split('=')
	if len(user)>=2:
		return user[1]
	return user[0]

def save():
	global scores
	json.dump(scores, open('logs/userData.txt','w'))

def updateScore(user, contestId, problemId, newScores):
	global users,scores, changed
	init()
	user = getActualName(user)
	if not user in users:
		users[user] = user
		scores[user] = {}
	pName = str(contestId)+str(problemId)
	if not pName in scores[user]:
		tmp, pscore = problem.getCasesInfo(contestId,problemId)
		scores[user][pName] = pscore
		for i in pscore.keys():
			scores[user][pName][i]=0
	for i in scores[user][pName].keys():
		scores[user][pName][i]=max(scores[user][pName][i],newScores[i])
	changed = True
	save()

def getTotal(e):
	return e['total']

def getProblems():
	global problems
	return sorted(list(problems))

def getUser(user):
	global users,scores
	init()
	if not user in scores.keys():
		return None
	if not user in users.keys():
			users[user]=user
	ret = scores[user]
	ret['name'] = users[user]
	return ret


def getColor(score,total):
	per = 1.0*score/total
	RB = int(255*(1-per))

	col = RB * 256*256 + 255*256 + RB
	col = int(col)
	return "%06x" % col


def getScoreBoard():
	global users, scores, problems, changed, scoreboardCache
	init()
	if not changed:
		return scoreboardCache
	changed = False
	scoreboard = []
	if len(scores.keys()) == 0:
		return scoreboard
	for user in scores.keys():
		if not user in users.keys():
			users[user]=user
		curEntity = {'name':users[user]}
		myTotal = 0
		for problem in problems:
			curTotal = 0
			if problem in scores[user]:
				for subtask in scores[user][problem].keys():
					curTotal = curTotal + scores[user][problem][subtask]
			curEntity[problem] = curTotal
			curEntity[problem+'Color'] = getColor(curTotal,100)
			myTotal = myTotal + curTotal
		curEntity['total']=myTotal
		curEntity['totalColor'] = getColor(myTotal,100*len(problems))
		curEntity['user'] = user
		scoreboard.append(curEntity)
	scoreboard=sorted(scoreboard,key=getTotal,reverse=True)
	scoreboard[0]['rank']=1
	for i in range(1,len(scoreboard)):
		if scoreboard[i]['total'] == scoreboard[i-1]['total']:
			scoreboard[i]['rank'] = scoreboard[i-1]['rank']
		else:
			scoreboard[i]['rank'] = i+1
	scoreboardCache = scoreboard
	return scoreboard
