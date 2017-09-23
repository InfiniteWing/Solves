def ans(h,m):
    for M in range(m+1,60):
        if(check(h,M)):
            return form(h,M)
    for H in range(h+1,24):
        for M in range(0,60):
            if(check(H,M)):
                return form(H,M)
    
    for H in range(0,h):
        for M in range(0,60):
            if(check(H,M)):
                return form(H,M)
    return "NaN"
        
    
def form(h,m):
    if(h<10):
        h='0'+str(h)
    else:
        h=str(h)
    if(m<10):
        m='0'+str(m)
    else:
        m=str(m)
    
    return "{}:{}".format(h,m)
    
            
def check(h,m):
    if(h>0):
        if(m<10):
            s1=str(h)+"0"+str(m)
        else:
            s1=str(h)+str(m)
    else:
        s1=str(m)
    
    s2 = list(s1)
    s2.reverse()
    s2=''.join(s2)
    return s1==s2
    
while True:
    try:
        n=int(input())
    except EOFError:
        break
    for i in range(n):
        s=input()
        d=s.split(':')
        h,m=int(d[0]),int(d[1])
        print(ans(h,m))
        
            