
while True:
    try:
        s=input()
    except EOFError:
        break
        
    d=s.split(' ')
    x1=int(d[0])
    y1=int(d[1])
    
    s=input()
    d=s.split(' ')
    x2=int(d[0])
    y2=int(d[1])
    
    s=input()
    d=s.split(' ')
    x3=int(d[0])
    y3=int(d[1])
    
    l12=(x1-x2)**2 + (y1-y2)**2
    l13=(x1-x3)**2 + (y1-y3)**2
    l23=(x3-x2)**2 + (y3-y2)**2
        
    
    if(l23 > l12):
        ox=x1-x2
        oy=y1-y2
        print("{} {}".format(x3-ox,y3-oy))
    elif(l13 > l12):
        ox=x2-x1
        oy=y2-y1
        print("{} {}".format(x3-ox,y3-oy))
    else:
        ox=x3-x1
        oy=y3-y1
        print("{} {}".format(x2-ox,y2-oy))
