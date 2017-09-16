en="abcdefghijklmnopqrstuvwxyz"
maps=[]

def add(s,maps):
	if(s==0):
		s=0
	elif(len(maps[len(maps)-1])==5):
		return
	global en
	if(len(maps)>0):
		ranges=len(maps)-1
		for c in maps[s:ranges]:
			for i in range(26):
				if(i<=en.index(c[len(c)-1])):
					continue
				maps.append(c+en[i])
		add(ranges+1,maps)
	else:
		for i in range(26):
			maps.append(en[i])
		add(0,maps)
	


add(0,maps)

while True:
	try:
		s=input()
	except EOFError:
		break
	
	try:
		print(maps.index(s)+1)
	except ValueError:
		print(0)
	