while True:
    try:
        n=int(input())
    except EOFError:
        break
    c={}
    for i in range(n):
        s=input()
        country=s.split(' ')[0]
        if(country not in c):
            c[country]=1
        else:
            c[country]+=1
    for k in sorted(c.keys()):
        print(k,c[k])