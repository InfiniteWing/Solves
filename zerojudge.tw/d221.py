while 1:
	n=int(input())
	if(n==0):
		break
	s=input()
	data=s.split()
	ans=[]
	for m in data:
		ans.append(int(m))
	ans.sort()
	cost=0
	tmp=0
	while 1:
		if(len(ans)==1):
			if(len(data)==1):
				cost+=ans[0]
			break
		a=ans[0]
		b=ans[1]
		tmp=a+b
		cost+=tmp
		ans.append(tmp)
		ans.remove(a)
		ans.remove(b)
		ans.sort()
	print(cost)
		