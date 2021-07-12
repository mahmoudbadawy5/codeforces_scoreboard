import problem

import os.path

users = {}
scores = {}


inited = False

def init():
	global inited, users, scores
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
	inited = True
	print(users)

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
	print(scores)
