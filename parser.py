from urllib.parse import unquote

dataFile = open("data.txt","r")
data = unquote(dataFile.read())
dataFile.close()

print(data)