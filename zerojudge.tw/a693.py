
while True:
	try:
		s=input()
	except EOFError:
		break
	data=s.split()
	n=int(data[0])
	m=int(data[1])
	
	foods=[]
	s=input()
	data=s.split()
	sum=0
	foods.append(0)
	for a in data:
		foods.append(int(a)+sum)
		sum+=int(a)
	for i in range(m):
		s=input()
		data=s.split()
		a=int(data[0])
		b=int(data[1])
		print(foods[b]-foods[a-1])