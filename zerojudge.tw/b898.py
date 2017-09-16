while 1:
	try:
		n=int(input())
	except:
		break
	for z in range(n):
		s=input()
		s=s.split()
		if(len(s[0])>len(s[1])):
			s[0],s[1]=s[1],s[0]
		if(len(s[1])>len(s[2])):
			s[1],s[2]=s[2],s[1]
		if(len(s[0])>len(s[1])):
			s[0],s[1]=s[1],s[0]
		if(len(s[1])>len(s[2])):
			s[1],s[2]=s[2],s[1]
		if(len(s[2])>len(s[1])):
			print(s[2])
		elif(len(s[1])>len(s[0])):
			for z in range(10000):
				n1=0
				n2=0
				for i in range(11*z,min(len(s[1]),11+11*z)):
					n1=n1*10+int(s[1][i])
					n2=n2*10+int(s[2][i])
				if(n1>n2):
					print(s[1])
					break
				elif(n2>n1):
					print(s[2])
					break
		else:
			for z in range(10000):
				n0=0
				n1=0
				n2=0
				for i in range(11*z,min(len(s[1]),11+11*z)):
					n0=n0*10+int(s[0][i])
					n1=n1*10+int(s[1][i])
					n2=n2*10+int(s[2][i])
				if(n1>n2 and n1>n0):
					print(s[1])
					break
				elif(n2>n1 and n2>n0):
					print(s[2])
					break
				elif(n0>n1 and n0>n2):
					print(s[0])
					break