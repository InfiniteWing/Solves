woman=[0]
man=[1]
for i in range(80):
	man.append(woman[i]+man[i])
	woman.append(man[i])
while True:
	try:
		n=int(input())
	except EOFError:
		break
	if(n==0):
		break
	
	print(woman[n-1]+man[n-1])
	
	