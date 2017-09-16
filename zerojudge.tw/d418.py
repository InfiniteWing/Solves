n=int(input())
primes=[9,8,7,6,5,4,3,2]
for i in range (n):
	ans=[]
	for j in range(10):
		ans.append(0)
	a=int(input())
	if(a==1):
		print(1)
		continue
	while a>1:
		c=False
		for j in range(8):
			if(a%primes[j]==0):
				ans[9-j]+=1
				a=a/primes[j]
				c=True
				break
		if c==False:
			break
	if(a>1):
		print("-1")
	else :
		s=""
		for j in range(10):
			for z in range(ans[j]):
				s+=str(j)
		print(s)