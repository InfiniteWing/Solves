index=0
while 1:
	try:
		n=int(input())
	except EOFError:
		break
	index+=1
	uses=[]
	highs={}
	for i in range(n):
		s=input()
		s=s.split()
		x=int(s[0])
		y=int(s[1])
		if(highs.get(x)==None):
			highs[x]=y
			uses.append(x)
		elif(highs.get(x)<y):
			highs[x]=y
			uses.append(x)
	uses=sorted(uses,reverse=True)
	print("Case {}:".format(index))
	ans=[]
	strs=""
	high=-1
	for i in uses:
		if(highs[i]>high):
			ans.insert(0,"("+str(i)+","+str(highs[i])+")")
			high=highs[i]
	print("Dominate Point: {}".format(len(ans)))
	for i in range(len(ans)):
		print(ans[i])
	