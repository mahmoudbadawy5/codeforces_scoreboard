import config

import mechanize
from bs4 import BeautifulSoup
import urllib
import http.cookiejar

cj = http.cookiejar.CookieJar()
br = mechanize.Browser()

loggedin = False

def login():
	global loggedin, cj, br
	if loggedin:
		return
	br.set_handle_robots(False)
	br.set_cookiejar(cj)
	br.open("https://codeforces.com/enter?back=%2F")

	br.select_form(nr=1)
	br.form['handleOrEmail'] = config.userName
	br.form['password'] = config.password
	br.submit()
	loggedin = True

def getPage(url):
	global br
	login()
	br.open(url)
	return br.response().read()