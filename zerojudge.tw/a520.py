while 1:
	try:
		s=input()
	except EOFError:
		break
	space=False
	now=0
	high=0
	for c in s:
		if(c==" "):
			if(space):
				now+=1
			else:
				space=True
				now=1
		else:
			if(now>high):
				high=now
				space=False
	ans=0
	while high>1:
		high=(int)(high/2)+high%2
		ans+=1
	print(ans)