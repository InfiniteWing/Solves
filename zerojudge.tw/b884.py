import math
while 1:
	try:
		n=int(input())
	except:
		break
	for i in range(n):
		s=input()
		s=s.split()
		a=abs(int(s[0]))
		b=abs(int(s[1]))
		t=100-a-b
		if(t<=30 and t>0):
			print("sad!")
		elif(t>30 and t<=60):
			print("hmm~~")
		elif(t>60 and t<100):
			print("Happyyummy")
		else:
			print("evil!!")