alert=[]
class Robot:
	def __init__(self,x, y, d,map,alert):
		self.x = x
		self.y = y
		self.alive = 1
		self.alert=alert
		self.lastLocation = map
		
		if(d=='W'):
			self.d = 1
		if(d=='N'):
			self.d = 2
		if(d=='E'):
			self.d = 3
		if(d=='S'):
			self.d = 4
		self.map=map
	def Action(self,c):
		if(c=='L'):
			self.d=self.d-1
			if(self.d<1):
				self.d=4
		if(c=='R'):
			self.d=self.d+1
			if(self.d>4):
				self.d=1
		if(c=='F'):
			self.Walk()
		if(self.x>map.x or self.y>map.y or self.x<0 or self.y<0):
			if(self.lastLocation in self.alert):
				self.x=self.lastLocation.x
				self.y=self.lastLocation.y
				return 1
			self.x=self.lastLocation.x
			self.y=self.lastLocation.y
			self.alive=0
			return 0
		return 1
	def Walk(self):
		self.lastLocation=Location(self.x,self.y)
		if(self.d==1):
			self.x-=1
		if(self.d==2):
			self.y+=1
		if(self.d==3):
			self.x+=1
		if(self.d==4):
			self.y-=1
		
class Location:
	def __init__(self,x,y):
		self.x = x
		self.y = y
	def __eq__(self, other):
		return self.x == other.x and self.y == other.y

l=input()
data=l.split()
map=Location(int(data[0]),int(data[1]))
face=["","W","N","E","S"]
while True:
	try:
		l=input()
	except EOFError:
		break
	data=l.split()
	robot=Robot(int(data[0]),int(data[1]),data[2],map,alert)
	l=input()
	for s in l:
		c=robot.Action(s)
		if(c==0):
			alert.append(robot.lastLocation)
			break
	if(robot.alive):
		print(robot.x,robot.y,face[robot.d],sep=" ")
	else:
		print(robot.x,robot.y,face[robot.d],"LOST",sep=" ")
