import math
def check(k,n):
    l=(k*(k-1))/2
    r=(n+k+1)*(n-k)/2
    if(l>r):
        return -1
    elif(l==r):
        return 0
    else:
        return 1
def n_get_k(n):
#                   k*(k-1)=(n+k+1)*(n-k)
#   simplified ->   2k^2=n^2+n  
    t=math.sqrt(float((n*n+n)/2))
    if(t.is_integer()):
        return int(t)
    return -1
    
'''    
for n in range(8,88888888):
    k=n_get_k(n)
    if(k>0):
        print(k,n)
'''
NS=[8,49,288,1681,9800,57121,332928,1940449,11309768,65918161]

for N in NS:
    n=str(N)
    while(len(n)<10):
        n=" "+n
    k=str(n_get_k(N))
    while(len(k)<10):
        k=" "+k
    print(k+n)
    