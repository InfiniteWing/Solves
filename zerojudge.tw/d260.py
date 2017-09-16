import math

n=int(input())
for i in range(n):
	s=input()
	data=s.split()
	l=[]
	for d in data:
		l.append(int(d))
	l.sort()
	if(l[0]==l[1] and l[1]==l[2] and l[2]==l[3]):
		print("square")
	elif(l[0]==l[1] and l[2]==l[3]):
		print("rectangle")
	elif(l[0]+l[1]+l[2]>l[3]):
		print("quadrangle")
	else:
		print("banana")
	