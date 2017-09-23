def base10tobase2(n):
    if(n==0):
        return ""
    return base10tobase2(int(n/2))+str(n%2)

def ans(a,b):
    if(len(b)>len(a)):
        a,b = b,a
    
    while(len(b)<len(a)):
        b="0"+b
    c=""
    for i in range(len(a)):
        if(a[i]==b[i]):
            c=c+"0"
        else:
            c=c+"1"
    return c

while True:
    try:
        s=input()
    except EOFError:
        break
    d=s.split(' ')
    a=base10tobase2(int(d[0]))
    b=base10tobase2(int(d[1]))
    print(int(ans(a,b),2))
