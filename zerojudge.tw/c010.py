maps=[]
while 1:
	try:
		n=int(input())
	except EOFError:
		break
	maps.append(n)
	maps.sort()
	if(len(maps)%2==0):
		ans=(maps[int(len(maps)/2)]+maps[int(len(maps)/2)-1])/2
	else:
		ans=maps[int(len(maps)/2)]
	print(int(ans))