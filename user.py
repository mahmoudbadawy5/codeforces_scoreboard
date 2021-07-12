import problem
import config
import api

import os.path

users = {}
scores = {}
problems = []

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
	curContestId = 1
	for contest in config.contestIds:
		data = {"contestId": contest}
		curProblems = api.callApi('contest.standings',data)
		if curProblems == None:
			continue
		for problem in curProblems['result']['problems']:
			problems.append(str(curContestId)+problem['index'])
		curContestId = curContestId+1
	inited = True

def getActualName(user):
	user = user.split('=')
	if len(user)>=2:
		return user[1]
	return user[0]

def updateScore(user, contestId, problemId, newScores):
	global users,scores
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

def getTotal(e):
	return e['total']

def getScoreBoard():
	global users, scores, problems
	scoreboard = []
	if len(users.keys()) == 0:
		return scoreboard
	for user in users.keys():
		curEntity = {'name':users[user]}
		myTotal = 0
		for problem in problems:
			curTotal = 0
			if problem in scores[user]:
				for subtask in scores[user][problem].keys():
					curTotal = curTotal + scores[user][problem][subtask]
			curEntity[problem] = curTotal
			myTotal = myTotal + curTotal
		curEntity['total']=myTotal
		scoreboard.append(curEntity)
	scoreboard=sorted(scoreboard,key=getTotal,reverse=True)
	scoreboard[0]['rank']=1
	for i in range(1,len(scoreboard)):
		if scoreboard[i]['total'] == scoreboard[i-1]['total']:
			scoreboard[i]['rank'] = scoreboard[i-1]['rank']
		else:
			scoreboard[i]['rank'] = i+1
	return scoreboard
