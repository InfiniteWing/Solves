import math
primes=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181]

while 1:
	s=input()
	data=s.split()
	if(len(data)==1 and int(data[0])==0):
		break
	n=1
	i=0
	while(i<len(data)):
		n*=pow(int(data[i]),int(data[i+1]))
		i+=2
	n-=1
	ans=[]
	for i in range(len(primes)):
		ans.append(0)
	for i in range(len(primes)-1,-1,-1):
		while(n%primes[i]==0):
			n=n/primes[i]
			ans[i]+=1
	ansStr=""
	if(n>181):
		ansStr+=str(int(n))+" 1"
	for i in range(len(primes)-1,-1,-1):
		if(ans[i]!=0):
			if(len(ansStr)>0):
				ansStr+=" "+str(primes[i])+" "+str(ans[i])
			else:
				ansStr+=str(primes[i])+" "+str(ans[i])
	print(ansStr)