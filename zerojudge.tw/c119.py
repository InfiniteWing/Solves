maps=[]
maps.append([1])
maps.append([1])
for i in range(2,1001):
	c=0
	maps.append([])
	for n in maps[i-1]:
		c+=i*n
		maps[i].append(c%10)
		c=int((c-c%10)/10)
	while c>0:
		maps[i].append(c%10)
		c=int((c-c%10)/10)
while True:
	try:
		n=int(input())
	except EOFError:
		break
	print(sum(maps[n]))
	
	