while 1:
	try:
		s=input()
	except:
		break
	s=s.split()
	w=int(s[0])
	h=int(s[1])
	maps=[]
	for i in range(h):
		maps.append(" "+input()+" ")
	ans=""
	for i in range(w):
		y=0
		x=i*2+1
		while(y<=h-1):
			if(maps[y][x+1]=='-'):
				x+=2
			elif(maps[y][x-1]=='-'):
				x-=2
			y+=1
		if(i!=0):
			ans+=" "
		ans+=str(int((x+1)/2))
	print(ans)