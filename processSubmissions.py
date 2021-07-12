import login
import parseSubmission
import problem
#import contestant

import math

def getSubmissionURL(contestId, submissionId):
	return 'https://codeforces.com/gym/'+str(contestId)+'/submission/'+str(submissionId)

def getTestResults(contestId,submission):
	tc = problem.getTestCount(contestId,submission['problem']['index'])
	result = [0 for _ in range(tc+1)]
	url = getSubmissionURL(submission['contestId'],submission['id'])
	res = login.getPage(url)
	tests = parseSubmission.parseSubmission(res)
	for test in tests:
		result[test['test']]=test['points']
	return result


def processSubmission(contestId,submission):
	testResults = getTestResults(contestId,submission)
	subtasks, points = problem.getCasesInfo(contestId,submission['problem']['index'])
	subtaskPoints = points
	for subtask in subtasks.keys():
		for test in subtasks[subtask]:
			if testResults[test]==-1:
				continue
			subtaskPoints[subtask]=min(testResults[test],subtaskPoints[subtask])
	return subtaskPoints