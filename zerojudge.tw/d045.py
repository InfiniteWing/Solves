while True:
    try:
        n=int(input())
    except EOFError:
        break
    
    for i in range(n):
        s=input()
        s=s.split(' ')
        a=[]
        for v in s:
            a.append(int(v))
        a=a[1:]
        a=set(a)
        
        s=input()
        s=s.split(' ')
        b=[]
        for v in s:
            b.append(int(v))
        b=b[1:]
        b=set(b)
        
        s=input()
        s=s.split(' ')
        c=[]
        for v in s:
            c.append(int(v))
        c=c[1:]
        c=set(c)
        
        a_ds=a-(b|c)
        b_ds=b-(a|c)
        c_ds=c-(a|b)
        print("Case #{}:".format(i+1))
        max_solves=max(len(a_ds),len(b_ds),len(c_ds))
        if(len(a_ds)==max_solves):
            s=sorted(list(a_ds))
            s=[str(v) for v in s]
            print("{} {} {}".format(1,max_solves,' '.join(s)))
        if(len(b_ds)==max_solves):
            s=sorted(list(b_ds))
            s=[str(v) for v in s]
            print("{} {} {}".format(2,max_solves,' '.join(s)))
        if(len(c_ds)==max_solves):
            s=sorted(list(c_ds))
            s=[str(v) for v in s]
            print("{} {} {}".format(3,max_solves,' '.join(s)))
        
        
        
        