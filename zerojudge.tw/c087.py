import math
prime=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181]
def Prime(a,b):
	global prime
	if(min(a,b)==1):
		return False
	for p in prime:
		if(a%p==0 and b%p==0):
			return False
	for p in prime:
		if(a%p==0):
			while(a%p==0):
				a=a/p
		if(b%p==0):
			while(b%p==0):
				b=b/p
	if(min(a,b)==1):
		return True
	if(max(a,b)%min(a,b)==0):
		return False
	return True
def C(n):
	sum=0
	for i in range(n):
		sum+=i
	return sum
while 1:
	n=int(input())
	if(n==0):
		break
	data=[]
	for i in range(n):
		data.append(int(input()))
	count=0
	for i in range(n):
		for j in range(i+1,n):
			if(Prime(data[i],data[j])):
				count+=1
	
	if(count>0):
		pi2=((C(n)*6))/(count)
		print("%.6f"%(math.sqrt(pi2)))
	else:
		print("No estimate for this data set.")
	