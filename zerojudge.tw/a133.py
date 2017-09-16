import math
index=1
while 1:
	if(index>1):
		print()
	s=input()
	data=s.split()
	a=int(data[0])
	b=int(data[1])
	if(a==0 and b==0):
		break
	n1=input()
	n2=input()
	dp=[]
	data1=n1.split()
	data2=n2.split()
	for i in range(a+1):
		dps=[]
		for j in range(b+1):
			dps.append(0)
		dp.append(dps)
	for i in range(a):
		for j in range(b):
			if(data1[i]==data2[j]):
				dp[i+1][j+1]=dp[i][j]+1
			else:
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])
	print("Twin Towers #{}".format(index))
	print("Number of Tiles : {}".format(dp[a][b]))
	index+=1