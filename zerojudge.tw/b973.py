while 1:
	try:
		s=input()
	except:
		break
	s=s.split()
	n=int(s[0])
	t=int(s[1])
	total=[0 for __ in range(t)]
	for i in range(n):
		s=input()
		s=s.split()
		for i,time in enumerate(s):
			total[i]+=int(time.split(":")[0])*60+int(time.split(":")[1])
	
	c=0
	while c!=t:
		m=min(total)
		for i,num in enumerate(total):
			if(num==m):
				print("{} {}".format(i+1,total[i]))
				total[i]=999999999
				c+=1
