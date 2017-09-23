def posible(y,a,b):
    p=[]
    p.append(y)
    d=y-a
    o=b-a
    n=0
    while True:
        ans=b+d+o*n
        if(ans>=10000):
            break
        p.append(ans)
        n+=1
    return p
case=1
while True:
    n=int(input())
    if(n==0):
        break
    p=[]
    for i in range(n):
        s=input()
        d=s.split(' ')
        y,a,b=int(d[0]),int(d[1]),int(d[2])
        p.append(posible(y,a,b))
    ans=10001
    for v in p[0]:
        not_found=False
        for i in range(len(p)-1):
            if(v not in p[i+1]):
                not_found=True
                break
        if(not_found):
            continue
        else:
            ans=v
            break
    if(case>1):
        print()
    print("Case #{}:".format(case))
    if(ans!=10001):
        print("The actual year is {}.".format(ans))
    else:
        print("Unknown bugs detected.")
    
    case+=1