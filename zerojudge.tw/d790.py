def Ans(c,n,h):
	if(len(c)==n):
		if(h==0):
			print(c)
	else:
		if(n-len(c)<h):
			return
		Ans(c+"0",n,h)
		Ans(c+"1",n,h-1)
		

n=int(input())
for i in range (n):
	input()
	s=input()
	data=s.split()
	a1=int(data[0])
	a2=int(data[1])
	Ans("",a1,a2)
	print()