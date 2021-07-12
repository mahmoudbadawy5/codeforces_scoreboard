from bs4 import BeautifulSoup

def parseSubmission(data):
	testData=[]
	soup = BeautifulSoup(data, 'html.parser')
	tests = soup.find_all('div', attrs={'class':'roundbox'})
	for test in tests:
		numberTag = test.find('div',attrs={'class':'caption titled'})
		if numberTag == None:
			continue
		number = numberTag.getText().split('\\n')[0]
		try:
			number=int(number)
		except:
			continue
		verdictTag = test.find_all('div',attrs={'class':'infoline'})[1]
		verdict = verdictTag.find('div').getText()
		checkerComment = test.find('div',attrs={'class':'file checker-comment-view'})
		checkerComment = checkerComment.find('div',attrs={'class':'text'})
		checkerComment = checkerComment.find('pre').getText().split(' ')
		points = -1
		if str(verdict) == 'Verdict: OK':
			if checkerComment[0]=='points':
				points=float(checkerComment[1])
			else:
				points=-1
		else:
			points = 0
		testData.append({'test':number,'points':points})
	return testData
		