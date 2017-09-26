while True:
    try:
        n=int(input())
    except EOFError:
        break
    k=input()
    for i in range(n):
        if(i>0):
            print
        m={}
        total=0
        while True:
            try:
                s=input()
            except EOFError:
                break
            if(s==""):
                break
            if(s not in m):
                m[s]=1
            else:
                m[s]+=1
            total+=1
        for k in sorted(m.keys()):
            p=round(100*m[k]/total,4)
            p1=str(p).split('.')[0]+"."
            p2=str(p).split('.')[1]
            while(len(p2)<4):
                p2=p2+"0"
            print(k,p1+p2)
    