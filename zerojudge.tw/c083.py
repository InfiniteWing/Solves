class People:
	def __init__(self,i):
		self.alive=True
		self.i=i

def Ans(n,k):
	i=0
	while i<n:
		p=[]
		for j in range(n):
			p.append(People(j+1))
		r=Kill(n,k,p,i,n)
		if(r==1):
			return i+1
		i+=1
	return 0

def Kill(n,k,p,i,a):
	k_i=0
	a_i=0
	
	if(int(a)==1):
		if(p[i].alive and p[i].i==1):
			return 1
		else:
			return 0
	else:
		c=0
		while c<k:
			for j in range(i,n):
				if(p[j].alive):
					c+=1
					if(c==k):
						p[j].alive=False
						k_i=j
						break
			
			if(c!=k):
				for j in range(0,i):
					if(p[j].alive):
						c+=1
						if(c==k):
							p[j].alive=False
							k_i=j
							break
		c=0
		while c<k:
			for j in range(k_i,n):
				if(p[j].alive):
					c+=1
					if(c==k):
						a_i=j
						break
			
			if(c!=k):
				for j in range(0,k_i):
					if(p[j].alive):
						c+=1
						if(c==k):
							a_i=j
							break
		p[a_i],p[k_i]=p[k_i],p[a_i]
		c=0
		while c<1:
			for j in range(k_i+1,n):
				if(p[j].alive):
					c+=1
					i=j
					break
			
			if(c!=1):
				for j in range(0,k_i+1):
					if(p[j].alive):
						c+=1
						i=j
						break
		return Kill(n,k,p,i,a-1)
	
while True:
	s=input()
	data=s.split()
	n=int(data[0])
	k=int(data[1])
	if(n==0 and k==0):
		break
	print(Ans(n,k))

