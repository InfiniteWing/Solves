while True:
	try:
		n=int(input())
	except EOFError:
		break
	map=[]
	s=input()
	data=s.split()
	for num in data:
		map.append(int(num))
	sum=0
	while True:
		c=False
		for i in range(len(map)):
			if(i==len(map)-1):
				break
			if(map[i]>map[i+1]):
				sum+=1
				c=True
				map[i],map[i+1]=map[i+1],map[i]
		if(not c):
			break
	print("Minimum exchange operations : {}".format(sum))