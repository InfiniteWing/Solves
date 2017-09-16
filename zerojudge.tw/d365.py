en=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
n=int(input())
def BFS(c,x,y,map,searches):
	if(x==-1 or y==-1 or x>=len(searches) or y >=len(searches[0])):
		return
	if(searches[x][y]==1):
		return
	if(map[x][y]==c):
		searches[x][y]=1
		BFS(c,x+1,y,map,searches)
		BFS(c,x-1,y,map,searches)
		BFS(c,x,y+1,map,searches)
		BFS(c,x,y-1,map,searches)
for z in range(n):
	s=input()
	data=s.split()
	x=int(data[0])
	y=int(data[1])
	searches=[]
	map=[]
	count=[]
	for i in range(26):
		count.append(0)
	for i in range(x):
		search=[]
		for j in range(y):
			search.append(0)
		searches.append(search)
	for i in range(x):
		map.append(input())
	for i in range(x):
		for j in range(y):
			if(searches[i][j]==1):
				continue
			count[en.index(map[i][j])]+=1
			BFS(map[i][j],i,j,map,searches)
	print("World #{}".format(z+1))
	for i in range(max(count)+1,0,-1):
		for j in range(26):
			if(count[j]==i):
				print("{}: {}".format(en[j],i))
	
	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
