index=1
while 1:
	try:
		n=int(input())
	except EOFError:
		break
	check=[]
	stack=[]
	ans=True
	for i in range(20001):
		check.append(0)
	s=input()
	s=s.split()
	for i in range(n):
		stack.append(int(s[i]))
	for i in range(n):
		for j in range(i,n):
			check[stack[i]+stack[j]]+=1
			if(check[stack[i]+stack[j]]>1):
				ans=False
				break
		if(not ans):
			break
	if(index>1):
		print()
	if(ans):
		print("Case #{}: It is a B2-Sequence.".format(index))
	else:
		print("Case #{}: It is not a B2-Sequence.".format(index))
	index+=1