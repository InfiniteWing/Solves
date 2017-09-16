import math
class point:
	def __init__(self, x, y):
		self.x = x
		self.y = y
n=int(input())
for z in range(n):
	m=int(input())
	mountains=[]
	for y in range(m):
		s=input()
		data=s.split()
		p=point(int(data[0]),int(data[1]))
		mountains.append(p)
	mountains=sorted(mountains,key=lambda point:point.x)
	high=0
	length=0
	for i in range(m-2,-1,-1):
		if(mountains[i].y>high):
			offsetY=mountains[i].y-mountains[i+1].y
			offsetX=mountains[i].x-mountains[i+1].x
			offset=offsetX/offsetY
			x=(mountains[i].x-(mountains[i].y-high)*offset)
			
			length+=math.sqrt((x-mountains[i].x)*(x-mountains[i].x)+(mountains[i].y-high)*(mountains[i].y-high))
			high=mountains[i].y
	print("%.2f"%length)