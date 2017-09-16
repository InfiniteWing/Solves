while 1:
	n=int(input())
	if(n==-1):
		break
	ans=((4+n)/4)*100-100
	if(n==1):
		ans=0
	print("{}%".format(int(ans)))
