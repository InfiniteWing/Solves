
while True:
    try:
        n=int(input())
    except EOFError:
        break
    t=1
    ans=1
    while(True):
        if(t%n==0):
            break
        t=t*10+1
        t=t%n        
        ans+=1
    print(ans)

'''
# TLE(3)
def ans(n):
    t=1
    while True:
        t=t*10+1
        if(t>=n):
            if(t%n==0):
                return len(str(t))
ans_map={}
while True:
    try:
        n=int(input())
    except EOFError:
        break
    if(n not in ans_map):
        ans_map[n]=ans(n)
    print(ans_map[n])
'''