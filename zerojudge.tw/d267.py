en=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
n=int(input())
for j in range(n):
	co=[]
	for i in range(26):
		co.append(0)
	s=input()
	s=s.lower()
	h=0
	ans=""
	for c in s:
		if(c in en):
			co[en.index(c)]+=1
			if(co[en.index(c)]>h):
				h=co[en.index(c)]
	for i in range(26):
		if(co[i]==h):
			ans+=en[i]
	print(ans)
	