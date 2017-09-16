n=int(input())
for i in range(n):
	s=input()
	data=s.split()
	map=[0,0]
	c=0
	for d in data:
		for w in d:
			if(w=="M"):
				map[0]+=1
			else:
				map[1]+=1
		c+=1
	if(c==1):
		map[0]=22
	if(map[0]==map[1]):
		print("LOOP")
	else:
		print("NO LOOP")