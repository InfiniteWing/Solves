def Search(a,step):
	i=0
	j=len(a)-1
	check=True
	while True:
		if i>=j:
			break
		if a[i]!=a[j]:
			check=False
			break
		i=i+1
		j=j-1
	if(step==0):
		check=False
	if(check):
		print(step,a)
		return
	
	x=int(a)
	y=GetNum(x)
	Search(str(x+y),step+1)
def GetNum(x):
	c=0
	while x>0:
		c=c*10+x%10
		x=int((x-x%10)/10)
	return c
n=int(input())
for i in range(n):
	c=int(input())
	Search(str(c),0)
	
	