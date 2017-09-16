def compare(a1,a2):

	return int(a1+a2)<int(a2+a1)

while True:
	try:
		n=int(input())
	except EOFError:
		break
	if(n==0):
		break
	map=[]
	s=input()
	data=s.split()
	for num in data:
		map.append(num)
	sum=0
	while True:
		c=False
		for i in range(len(map)):
			if(i==len(map)-1):
				break
			if(compare(map[i],map[i+1])):
				sum+=1
				c=True
				map[i],map[i+1]=map[i+1],map[i]
		if(not c):
			break
	s2=""
	for n in map:
		s2+=n
	print(s2)