
layer=[]
i=1
j=2
while i < 10000000:
	layer.append(i)
	i=i+j
	j+=1
layer.append(i)
while True:
	try:
		n=int(input())
	except EOFError:
		break
	x=0
	y=0
	i=0
	for a in layer:
		if(a>=n):
			break
		i=i+1
	if(i%2==0):
		x=1+i-(layer[i]-n)
		y=1+(layer[i]-n)
	else:
		x=1+(layer[i]-n)
		y=1+i-(layer[i]-n)
	print('TERM {} IS {}/{}'.format(n,y,x))
	