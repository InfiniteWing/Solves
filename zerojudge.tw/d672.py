def Ans(o,n,c):
#	a=[]
#	i=len(n)-1
#	s=0
#	while(i>=0):
#		s=s*10+int(n[i])
#		if(s<9):
#			a.append(0)
#		else:
#			a.append(int((s-s%9)/9))
#			s=s%9
#		i=i-1
	s=0
	for i in range(len(n)):
		s+=int(n[i])
	if(s==9):
		c+=1
		print("{} is a multiple of 9 and has 9-degree {}.".format(o,c))
	elif(s%9!=0 or s==0):
		if(c>0):
			print("{} is a multiple of 9 and has 9-degree {}.".format(o,c))
		else:
			print("{} is not a multiple of 9.".format(o))
	else:
#		ss=""
#		for s in a:
#			ss+=str(s)
		Ans(o,str(s),c+1)

while True:
	s=input()
	if int(s)==0 and len(s)==1:
		break
	Ans(s,s,0)