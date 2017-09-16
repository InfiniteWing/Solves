case=0
while True:
	s1=input()
	if(s1=="#"):
		break
	s2=input()
	maps=[]
	map=[]
	map.append(0)
	for j in range(len(s2)):
		map.append(0)
	maps.append(map)
	for i in range(len(s1)):
		map=[]
		map.append(0)
		for j in range(len(s2)):
			map.append(0)
		maps.append(map)
	
	for i in range(len(s1)):
		for j in range(len(s2)):
			if(s1[i]==s2[j]):
				maps[i+1][j+1]=1+maps[i][j]
			else:
				maps[i+1][j+1]=max(maps[i+1][j],maps[i][j+1])
	
	print("Case #{}: you can visit at most {} cities.".format(case+1,maps[len(s1)][len(s2)]))
	case+=1