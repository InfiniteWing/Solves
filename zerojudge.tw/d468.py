while 1:
	s=input()
	data=s.split()
	a=int(data[0])
	b=int(data[1])
	if(a==0 and b==0):
		print("All Over.")
		break
	print(pow(a,b))