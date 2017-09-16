import math
def Base2ToBase10(n):
	base10=0
	for i in range(len(n)):
		if(n[i]=="1"):
			base10+=pow(2,len(n)-i-1)
	return base10
while 1:
	base1=input()
	if(len(base1)==1):
		break
	base2=""
	base1=base1.split()
	
	flag="0"
	for n in base1:
		if(n=="#"):
			break
		elif(n=="0"):
			flag="1"
		elif(n=="00"):
			flag="0"
		else:
			for j in range(len(n)-2):
				base2+=flag
	print(Base2ToBase10(base2))