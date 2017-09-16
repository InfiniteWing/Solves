def BaseNtoBase10(base,n):
	mod=['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
	num=0
	base=int(base)
	for i in range(len(n)):
		for j in range(base):
			if(n[i]==mod[j]):
				num+=j*pow(base,len(n)-i-1)
				break
	return str(num)
	
def Base10toBaseN(base,n):
	mod=['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
	ans=""
	num=int(n)
	base=int(base)
	while(num>0):
		ans+=mod[num%base]
		num=int(num/base)
	ans2=""
	for i in range(len(ans)):
		ans2+=ans[len(ans)-i-1]
	return ans2
	
while 1:
	try:
		s=input()
	except EOFError:
		break
	s=s.split()
	ans=Base10toBaseN(s[2],BaseNtoBase10(s[1],s[0]))
	finalAns=""
	for i in range(7-len(ans)):
		finalAns+=" "
	finalAns+=ans
	if(len(ans)>7):
		print("  ERROR")
	else:
		print(finalAns)
	
	
	
	
	
	
	