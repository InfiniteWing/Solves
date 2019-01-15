mod_string = '0123456789abcdefghijklmnopqrstuvwxyz'
mod = [v if v.isdigit() else v.upper() for v in mod_string]
def BaseNtoBase10(base,n):
	num=0
	base=int(base)
	for i in range(len(n)):
		for j in range(base):
			if(n[i]==mod[j]):
				num+=j*pow(base,len(n)-i-1)
				break
	return str(num)
	
def Base10toBaseN(base,n):
	ans=""
	num=int(n)
	base=int(base)
	while(num>0):
		ans+=mod[num%base]
		num=int(num/base)
	ans2=""
	for i in range(len(ans)):
		ans2+=ans[len(ans)-i-1]
	return ans2
	
while True:
	try:
		s = input()
	except EOFError:
		break
	s = s.split()
	ans = Base10toBaseN(s[2],BaseNtoBase10(s[1],s[0]))
	print(ans)