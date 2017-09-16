import math

n=int(input())
for i in range(n):
	s=input()
	a=int(math.sqrt(len(s)))
	if(a*a!=len(s)):
		print("INVALID")
	else:
		maps=[]
		for i in range(a):
			map=[]
			for j in range(a):
				map.append(s[i*a+j])
			maps.append(map)
		s=""
		for i in range(a):
			for j in range(a):
				s+=(maps[j][i])
		print(s)