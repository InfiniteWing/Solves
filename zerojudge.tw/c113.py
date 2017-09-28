import math
PI=3.141592653589793
def form(n):
    x=str(n)
    while(True):
        if(len(x.split('.')[1])<2):
            x=x+"0"
        else:
            break
    return x
def ans(x1,y1,x2,y2,x3,y3,x4,y4):
    m1_use=True
    m2_use=True
    if(x1-x2==0):
        m1_use=False
    elif(y1-y2==0):
        m1=0
    else:
        m1=((y1-y2)/(x1-x2))
    if(x3-x4==0):
        m2_use=False
    elif(y3-y4==0):
        m2=0
    else:
        m2=((y3-y4)/(x3-x4))
    
    
    if(m2_use and m1_use):
        if(m1==m2):
            c1=y1-x1*m1
            c2=y3-x3*m2
            if(c1==c2):
                print("LINE")
            else:
                print("NONE")
        else:
            X=(y1-y3+x3*m2-x1*m1)/(m2-m1)
            Y=y1+(X-x1)*m1
            x=round(X,2)
            x=form(x)
            y=round(Y,2)
            y=form(y)
            
            print("POINT {} {}".format(x,y))
    elif(m1_use==False and m2_use==False):
        if(x1==x3):
            print("LINE")
        else:
            print("NONE")
    elif(m1_use==False):
        X=x1
        c=y3-x3*m2
        Y=X*m2+c
        x=round(X,2)
        x=form(x)
        y=round(Y,2)
        y=form(y)
        
        print("POINT {} {}".format(x,y))
    elif(m2_use==False):
        X=x3
        c=y1-x1*m1
        Y=X*m1+c
        x=round(X,2)
        x=form(x)
        y=round(Y,2)
        y=form(y)
        
        print("POINT {} {}".format(x,y))
    
while True:
    try:
        n=int(input())
    except EOFError:
        break
    print("INTERSECTING LINES OUTPUT")
    for i in range(n):
        s=input()
        d=s.split(' ')
        x1,y1,x2,y2,x3,y3,x4,y4=float(d[0]),float(d[1]),float(d[2]),float(d[3]),float(d[4]),float(d[5]),float(d[6]),float(d[7])
        ans(x1,y1,x2,y2,x3,y3,x4,y4)
    print("END OF OUTPUT")