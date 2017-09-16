while 1:
	try:
		n=int(input())
	except:
		break
	stacks=[]
	for z in range(n):
		s=input()
		s=s.split()
		if(int(s[0])==3):
			stacks.append(int(s[1]))
		if(int(s[0])==2):
			print(stacks[len(stacks)-1])
		if(int(s[0])==1):
			del stacks[len(stacks)-1]