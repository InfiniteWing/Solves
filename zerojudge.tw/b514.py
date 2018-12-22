while True:
    try:
        n = int(input())
    except EOFError:
        break
    for _ in range(n):
        s = input()
        a,b,c,d,e,f=int(s.split()[0]),int(s.split()[1]),int(s.split()[2]),int(s.split()[3]),int(s.split()[4]),int(s.split()[5])
        y = int((c*d-a*f)/(b*d -a*e))
        if(a != 0):
            x = int((c - b*y)/a)
        else:
            x = int((f - e*y)/d)
        print(x,y)