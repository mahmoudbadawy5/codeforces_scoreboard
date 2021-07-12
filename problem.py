import xml.etree.ElementTree as ET

def getch(root,chtag,chname):
	for ch in root:
		name="-2"
		if "name" in ch.attrib:
			name=ch.attrib["name"]
		if ch.tag == chtag and (chname == "-1" or chname==name):
			return ch

def getCases(contestId,index):
	tree = ET.parse('data/'+str(contestId)+str(index)+'.xml').getroot()

	tests=getch(tree,'judging','-1')
	tests=getch(tests,'testset','tests')
	cases=getch(tests,'tests','-1')
	subtasks=getch(tests,'groups','-1')
	return cases,subtasks


def getTestCount(contestId,index):
	tree = ET.parse('data/'+str(contestId)+str(index)+'.xml').getroot()

	tests=getch(tree,'judging','-1')
	tests=getch(tests,'testset','tests')
	cases=getch(tests,'tests','-1')
	return len(cases)


def getCasesInfo(contestId,index):
	cases,subtasks = getCases(contestId,index)
	subtests = {}
	fulltests = {}
	points = {}
	caseCount=1
	for case in cases:
		if not 'group' in case.attrib:
			return None,None
		if not (case.attrib['group'] in subtests):
			subtests[case.attrib['group']]=[]
		subtests[case.attrib['group']].append(caseCount)
		caseCount = caseCount+1

	for subtask in subtasks:
		name=subtask.attrib['name']
		points[name]=float(subtask.attrib['points'])
		fulltests[name]=subtests[name][:]
		dependencies=getch(subtask,'dependencies','-1')
		if dependencies is None:
			continue
		for dep in dependencies:
			depname=dep.attrib['group']
			for test in subtests[depname]:
				fulltests[name].append(test)
	return fulltests,points
