def search(x,y,maps,checks):
	if(x<0 or y < 0):
		return
	if(x>len(maps[0])-1):
		return
	if(y>len(maps)-1):
		return
	if(checks[y][x]==1):
		return
	checks[y][x]=1
	if(maps[y][x]=="@"):
		search(x-1,y,maps,checks)
		search(x-1,y-1,maps,checks)
		search(x-1,y+1,maps,checks)
		search(x,y-1,maps,checks)
		search(x,y+1,maps,checks)
		search(x+1,y,maps,checks)
		search(x+1,y-1,maps,checks)
		search(x+1,y+1,maps,checks)
	

while True:
	s=input()
	data=s.split()
	y=int(data[0])
	x=int(data[1])
	if(x==0 and y==0):
		break
	checks=[]
	maps=[]
	for i in range(y):
		array=[]
		for j in range(x):
			array.append(0)
		checks.append(array)
	for i in range(y):
		maps.append(input())
	ans=0
	for i in range(y):
		for j in range(x):
			if(maps[i][j]=="@" and checks[i][j]==0):
				ans+=1
				search(j,i,maps,checks)
	print(ans)
	