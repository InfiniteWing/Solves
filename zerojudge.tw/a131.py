codes=[]
codes.append(['A', 'E', 'I', 'O', 'U', 'Y', 'W', 'H'])
codes.append(['B','P','F','V'])
codes.append(['C','S','K','G','J','Q','X','Z'])
codes.append(['D','T'])
codes.append(['L'])
codes.append(['M','N'])
codes.append(['R'])

def Encode(s):
	global codes
	for i in range(len(codes)):
		try:
			if(codes[i].index(s)>=0):
				return i
		except ValueError:
			i
	return 
	
print("NAME                     SOUNDEX CODE")
while True:
	try:
		s=input()
	except EOFError:
		break
		
	c=s[0]
	last=Encode(s[0])
	for i in range(len(s)):
		if(i==0):
			continue
		if(len(c)==4):
			break
		now=Encode(s[i])
		if(now!=0):
			if(now!=last):
				c+=str(now)
		
		last=now
	ans="         "+s
	l=25-len(s)
	for i in range(l):
		ans+=" "
	while(len(c)<4):
		c+="0"
	ans+=c
	
	print(ans)
print("                   END OF OUTPUT")