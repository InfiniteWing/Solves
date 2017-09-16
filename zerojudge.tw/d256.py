n=int(input())
for i in range(n):
	s=input()
	data=s.split()
	
	a=int(data[0])
	b=int(data[1])
	if(b%a==0):
		print(a,b)
	else:
		print(-1)
