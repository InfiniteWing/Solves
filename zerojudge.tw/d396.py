prime=[2,3,5,7,11,13,17,19,23,29,31]
def search(s,n,l):
	if(l==n):
		if(chk(s)):
			ans=""
			for i in range(n):
				if(i==0):
					ans+=str(s[i])
				else:
					ans+=" "+str(s[i])
			print(ans)
		return
	
	for i in range(1,n+1):
		if(i in s):
			continue
		s[l]=i
		if(chk(s)):
			search(s,n,l+1)
		s[l]=0
		
def chk(s):
	global prime
	for i in range(len(s)):
		if(i==len(s)-1):
			t=s[i]+s[0]
		else:
			if(s[i+1]==0):
				break
			t=s[i]+s[i+1]
		if(not t in prime):
			return False
	return True
index=1
while 1:
	if(index!=1):
		print()
	try:
		n=int(input())
	except EOFError:
		break
	s=[]
	for i in range(n):
		s.append(0)
	s[0]=1
	print("Case {}:".format(index))
	index+=1
	search(s,n,1)
