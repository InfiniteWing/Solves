def decode(s):
	n=0
	for i in range(2,10):
		if(s[i]=="o"):
			if(i<6):
				n+=pow(2,(8-i))
			else:
				n+=pow(2,(9-i))
	return n
step=0
ans=""
while 1:
	try:
		s=input()
	except EOFError:
		break
	if(s=="___________"):
		step+=1
	else:
		ans+=chr(decode(s))
	if(step%2==0):
		print(ans)
		ans=""