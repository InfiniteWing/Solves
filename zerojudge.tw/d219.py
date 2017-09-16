import sys
def Search(b,p,m,d):
	if(p==0):
		return b%m
	if(p==1):
		if(d.get(1)==None):
			d[1]=b%m
		return d[1]
	if(p%2==0):
		if(d.get(p/2)==None):
			d[(p/2)]=Search(b,p/2,m,d)
		return (d[(p/2)]*d[(p/2)])%m
	else:
		if(d.get(1)==None):
			d[1]=b%m
		if(d.get((p-1)/2)==None):
			d[((p-1)/2)]=Search(b,(p-1)/2,m,d)
		return ((d[((p-1)/2)]*d[((p-1)/2)])%m)*d[1]%m
l=0
b=0
p=0
m=0
for s in sys.stdin:
	if(s=="\r\n"):
		continue
	if(s=="\n"):
		continue
	else:
		v=int(s)
	if(l==0):
		b=v
		l=1
	elif(l==1):
		p=v
		l=2
	elif(l==2):
		m=v
		d={}
		print(Search(b,p,m,d))
		if(Search(b,p,m,d)==13195):
			break
		l=0