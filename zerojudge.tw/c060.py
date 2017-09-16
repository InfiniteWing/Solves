while 1:
	try:
		s=input()
	except EOFError:
		break
	s=s.split()
	ans=""
	for i in range(len(s)):
		n=int(s[i])
		if(n==0):
			continue
		if(len(ans)>0):
			ans+=" "
			if(i==7):
				if(n==1):
					ans+="+ x"
				elif(n==-1):
					ans+="- x"
				elif(n>0):
					ans+="+ "+str(n)+"x"
				else:
					ans+="- "+str(abs(n))+"x"
			elif(i<8):
				if(n==1):
					ans+="+ x^"+str(8-i)
				elif(n==-1):
					ans+="- x^"+str(8-i)
				elif(n>0):
					ans+="+ "+str(n)+"x^"+str(8-i)
				else:
					ans+="- "+str(abs(n))+"x^"+str(8-i)
			else:
				if(n>0):
					ans+="+ "+str(n)
				else:
					ans+="- "+str(abs(n))
		else:
			if(i==7):
				if(n==1):
					ans+="x"
				elif(n==-1):
					ans+="-x"
				else:
					ans+=str(n)+"x"
			elif(i<8):
				if(n==1):
					ans+="x^"+str(8-i)
				elif(n==-1):
					ans+="-x^"+str(8-i)
				else:
					ans+=str(n)+"x^"+str(8-i)
			else:
				ans+=str(n)
	print(ans)
	if(len(ans)==0):
		print(0)
