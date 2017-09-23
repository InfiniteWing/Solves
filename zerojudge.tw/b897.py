# Vesion 3
# Use the Stirling's approximation with log base 10
import math

def digit(n):
    if(n==0):
        return 0
    return (0.5*(math.log10(2*math.pi*n))+n*math.log10(n)-n)

while True:
    try:
        s=input()
    except EOFError:
        break
    d=s.split(' ')
    n=int(d[0])
    k=int(d[1])
    ans=math.ceil(digit(n)-digit(n-k)-digit(k))
    if(ans==0):
        ans=1
    print(ans)

'''
# Version 2
# faster than ver.1
import math

def C(n,k):
    ans=0
    for i in range(k):
        ans+=math.log10(n-i)
        ans-=math.log10(k-i)
    return math.ceil(ans)
while True:
    try:
        s=input()
    except EOFError:
        break
    d=s.split(' ')
    n=int(d[0])
    k=int(d[1])
    print(C(n,k))
'''
'''
# Version 1
from decimal import *

def GCD(m, n):
    return m if n == 0 else GCD(n, m % n)
    
def C(n,k):
    t=[]
    d=[]
    for i in range(k):
        t.append((n-i))
        d.append((k-i))
    
    for i,v in enumerate(t):
        for j in range(k):
            if(d[j]==1):
                continue
            gcd=GCD(t[i],d[j])
            if(gcd>1):
                t[i]=t[i]/gcd
                d[j]=d[j]/gcd
            if(t[i]==1):
                break
    nt=[]
    nd=[]
    check=False
    ans=Decimal(1)
    for v in t:
        if(v>1):
            ans=ans*Decimal(v)
    
    for v in d:
        if(v>1):
            ans=ans/Decimal(v)
    
    return len(str(int(ans)))
    
while True:
    try:
        s=input()
    except EOFError:
        break
    d=s.split(' ')
    n=int(d[0])
    k=int(d[1])
    print(C(n,k))
'''