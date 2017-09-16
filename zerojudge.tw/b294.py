while 1:
	try:
		n=int(input())
	except:
		break
	s=input()
	s=s.split()
	sum=0
	for i in range(n):
		sum+=int(s[i])*(i+1)
	print(sum)