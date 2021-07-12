'''
import getSubmissions
import parseSubmission


f = open('subPage.txt','r')

data = f.read()
print(parseSubmission.parseSubmission(data))
'''
'''
import problem

print(problem.getTestCount(1,'A'))
print(problem.getCasesInfo(1,'A'))
print(problem.getTestCount(1,'D'))
print(problem.getCasesInfo(1,'D'))

import getSubmissions

getSubmissions.updateSubmissions()
'''
print("Hello")

import getSubmissions
print("World")
import user
print("Why??")

getSubmissions.updateSubmissions()
print(user.getScoreBoard())