case=1
while True:
    try:
        s=input()
    except EOFError:
        break
    d=s.split(' ')
    n,m=int(d[0]),int(d[1])
    if(n==0):
        break
    names=[]
    length=[]
    for i in range(n+1):
        length.append([])
        for j in range(n+1):
            length[i].append(999999)
        length[i][i]=0
    for i in range(n):
        names.append(input())
    for i in range(m):
        s=input()
        d=s.split(' ')
        r1,r2,l=int(d[0]),int(d[1]),int(d[2])
        length[r1][r2]=l
        length[r2][r1]=l
    for i in range(1,n+1):
        for j in range(1,n+1):
            for k in range(1,n+1):
                if(length[j][k]>length[j][i]+length[i][k]):
                    length[j][k]=length[j][i]+length[i][k]
    
    total=999999
    ansi=0
    for i in range(1,n+1):
        s=0
        for j in range(1,n+1):
            s+=length[i][j]
        if(s<total):
            ansi=i-1
            total=s
    print("Case #{} : {}".format(case,names[ansi]))
    case+=1
        