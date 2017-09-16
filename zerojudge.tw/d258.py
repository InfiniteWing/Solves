c=int(input())
for i in range(c):
	s=input()
	data=s.split()
	n=int(data[0])
	m=int(data[1])
	round=0
	while n>=m:
		round+=int(n/m)
		n=n%m+int(n/m)
	if(n==m):
		print(round+1)
	elif(n==1):
		print(round)
	else:
		print("cannot do this")