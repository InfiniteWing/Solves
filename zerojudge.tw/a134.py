
Faz=[]
Faz.append(0)
Faz.append(1)
for i in range(2,50):
	if(Faz[i-1]+Faz[i-2]>100000000):
		break
	Faz.append(Faz[i-1]+Faz[i-2])

n=int(input())
for i in range(n):
	a=int(input())
	ans=""
	check=False
	aa=a
	j=len(Faz)-1
	while (j>=2):
		if(not check):
			if(a>=Faz[j]):
				check=True
				ans+="1"
				a=a-Faz[j]
		else:
			if(a>=Faz[j]):
				ans+="1"
				a=a-Faz[j]
			else:
				ans+="0"
		j-=1
	print("{} = {} (fib)".format(aa,ans))