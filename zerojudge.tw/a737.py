import math
n=int(input())
for z in range(n):
	s=input()
	s=s.split()
	data=[]
	for i in range(len(s)):
		if(i==0):
			continue
		data.append(int(s[i]))
	data.sort()
	ans=0
	c=int((len(data)-1)/2)
	for i in range(c):
		ans+=(data[c]-data[i])
	for i in range(len(data)-1,c,-1):
		ans+=(data[i]-data[c])
	print(ans)