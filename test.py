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

import user

user.init()
user.updateScore('eoi001',1,'A',{'subtask1':13,'subtask2':0,'subtask3':23,'subtask4':0})
user.updateScore('eoi001',1,'A',{'subtask1':0,'subtask2':27,'subtask3':0,'subtask4':0})

print('')
print(user.getScoreBoard())