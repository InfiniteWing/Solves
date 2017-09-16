
n=int(input())
for i in range(n):
	q=input()
	a=input()
	if(q==a):
		print("Case {}: Yes".format(i+1))
	else:
		q=q.replace(" ","")
		a=a.replace(" ","")
		if(q==a):
			print("Case {}: Output Format Error".format(i+1))
		else:
			print("Case {}: Wrong Answer".format(i+1))

			