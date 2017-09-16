def Reverse(n):
	c=0
	while(n>0):
		c=c*10
		c+=n%10
		n=int((n-n%10)/10)
	return c

n=int(input())


for i in range (n):
	s=input()
	data=s.split()
	a1=int(data[0])
	a2=int(data[1])
	print(Reverse(Reverse(a1)+Reverse(a2)))