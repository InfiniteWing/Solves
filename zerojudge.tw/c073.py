class Box:
	def __init__(self,id):
		self.id=id


while True:
	try:
		n=int(input())
	except EOFError:
		break
	boxLists=[]
	for i in range(n):
		boxLists.append([Box(i)])
	while True:
		s=input()
		data=s.split()
		if(data[0]=="quit" or data=="quit"):
			break
		a=int(data[1])
		b=int(data[3])
		if(a==b):
			continue
		a_box=0
		b_box=0
		i=0
		for boxList in boxLists:
			for box in boxList:
				if box.id==a:
					a_box=i
				if box.id==b:
					b_box=i
			i+=1
		if(a_box==b_box):
			continue
			
		if(data[0]=="move"):
			if(data[2]=="onto"):
				check=False
				remove=[]
				for box in boxLists[b_box]:
					if(check):
						boxLists[box.id].append(box)
						remove.append(box)
					else:
						if(box.id==b):
							check=True
				for box in remove:
					boxLists[b_box].remove(box)
				check=False
				remove=[]
				for box in boxLists[a_box]:
					if(check):
						boxLists[box.id].append(box)
						remove.append(box)
					else:
						if(box.id==a):
							check=True
							boxLists[b_box].append(box)
							remove.append(box)
				for box in remove:
					boxLists[a_box].remove(box)
					
			elif(data[2]=="over"):
				check=False
				remove=[]
				for box in boxLists[a_box]:
					if(check):
						boxLists[box.id].append(box)
						remove.append(box)
					else:
						if(box.id==a):
							check=True
							boxLists[b_box].append(box)
							remove.append(box)
				for box in remove:
					boxLists[a_box].remove(box)
		elif(data[0]=="pile"):
			if(data[2]=="onto"):
				check=False
				remove=[]
				for box in boxLists[b_box]:
					if(check):
						boxLists[box.id].append(box)
						remove.append(box)
					else:
						if(box.id==b):
							check=True
				check=False
				for box in remove:
					boxLists[b_box].remove(box)
				remove=[]
				for box in boxLists[a_box]:
					if(check):
						boxLists[b_box].append(box)
						remove.append(box)
					else:
						if(box.id==a):
							check=True
							boxLists[b_box].append(box)
							remove.append(box)
				for box in remove:
					boxLists[a_box].remove(box)
			elif(data[2]=="over"):
				check=False
				remove=[]
				for box in boxLists[a_box]:
					if(check):
						boxLists[b_box].append(box)
						remove.append(box)
					else:
						if(box.id==a):
							check=True
							boxLists[b_box].append(box)
							remove.append(box)
				for box in remove:
					boxLists[a_box].remove(box)
	
	i=0
	for boxList in boxLists:
		s=str(i)+":"
		for box in boxList:
			s+=" " + str(box.id)
		i+=1
		print(s)