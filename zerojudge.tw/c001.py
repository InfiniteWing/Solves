def LCS(s1,s2,n,m):
	if(n==0 or m==0):
		return 0
	if(s1[n]==s2[m]):
		return LCS(s1,s2,n-1,m-1)+1
	else:
		return max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1))

while True:
	try:
		s1=input()
	except EOFError:
		break
	s2=input()
	DP=[]
	for i in range(len(s1)):
		dp=[]
		for j in range(len(s2)):
			dp.append(0)
		DP.append(dp)
	for i in range(len(s1)):
		for j in range(len(s2)):
			if(s1[i]==s2[j]):
				if(i==0 or j==0):
					DP[i][j]=1
				else:
					DP[i][j]=(1+DP[i-1][j-1])
			else:
				if(i==0 and j==0):
					continue
				elif(i==0):
					DP[i][j]=(DP[i][j-1])
				elif(j==0):
					DP[i][j]=(DP[i-1][j])
				else:
					DP[i][j]=(max(DP[i-1][j],DP[i][j-1]))

	print(DP[len(s1)-1][len(s2)-1])