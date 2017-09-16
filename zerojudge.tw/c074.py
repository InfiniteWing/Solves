numbers=[]
stack=[]
def Show(index):
	global numbers
	global stack
	l=len(numbers)
	for i in range(index,l):
		if(l-i<6-len(stack)):
			break
		stack.append(numbers[i])
		if(len(stack)==6):
			print(stack[0],stack[1],stack[2],stack[3],stack[4],stack[5])
		else:
			Show(i+1)
		stack.remove(numbers[i])

while True:
	try:
		l=input()
	except EOFError:
		break
	data=l.split()
	if(int(data[0])==0):
		break
	else:
		numbers=[]
		stack=[]
		for i in range(int(data[0])):
			numbers.append(int(data[i+1]))
		Show(0)
			
		
