def Ans(s):
	c=0
	check=["a","e","i","o","u","y"]
	preCheck=False
	step=1
	slashCount=s.count('/')
	
	for w in s:
		if(w=="/"):
			if(step==1):
				if(slashCount==2):
					if(c!=5):
						print("1")
						return
					else:
						step=2
						slashCount-=1
						c=0
				else:
					if(c>=5):
						if(c==5):
							step=2
							slashCount-=1
							c=0
						else:
							print("1")
							return
					else:
						slashCount-=1
			elif(step==2):
				if(slashCount==1):
					if(c!=7):
						print("2")
						return
					else:
						step=3
						slashCount-=1
						c=0
				else:
					if(c>=7):
						if(c==7):
							step=3
							slashCount-=1
							c=0
						else:
							print("2")
							return
					else:
						slashCount-=1
			preCheck=False
			continue
		if(not preCheck):
			if(w in check):
				preCheck=True
				c+=1
			else:
				preCheck=False
		else:
			if(w in check):
				preCheck=True
			else:
				preCheck=False
	if(c==5):
		print("Y")
	else:
		print("3")
while True:
	s=input()
	data=s.split('/')
	if(data[0]=='e' and data[1]=='o' and data[2]=='i'):
		break
	Ans(s)

