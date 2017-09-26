import math
PI=3.141592653589793
def ans(x1,y1,x2,y2,x3,y3):
    m12_use=True
    m13_use=True
    if(x1-x2==0):
        m12=0
    elif(y1-y2==0):
        m12_use=False
    else:
        m12=-1/((y1-y2)/(x1-x2))
    if(x1-x3==0):
        m13=0
    elif(y1-y3==0):
        m13_use=False
    else:
        m13=-1/((y1-y3)/(x1-x3))
        
    c12_x=(x1+x2)/2
    c12_y=(y1+y2)/2
    c13_x=(x1+x3)/2
    c13_y=(y1+y3)/2
    
    if(m13_use and m12_use):
        X=(c12_y-c13_y+c13_x*m13-c12_x*m12)/(m13-m12)
        Y=c12_y+(X-c12_x)*m12
    elif(m12_use==False and m13_use==False):
        X=c12_x
        Y=(c12_y+c13_y)/2
    elif(m12_use==False):
        X=c12_x
        Y=c13_y-(c13_x-X)*m13
    elif(m13_use==False):
        X=c13_x
        Y=c12_y-(c12_x-X)*m12
    
    return r(math.sqrt((X-x1)**2 + (Y-y1)**2)*2*PI)
def r(n):
    return round(n*100)/100
while True:
    try:
        s=input()
    except EOFError:
        break
    d=s.split(' ')
    x1,y1,x2,y2,x3,y3=float(d[0]),float(d[1]),float(d[2]),float(d[3]),float(d[4]),float(d[5])
    print(ans(x1,y1,x2,y2,x3,y3))
            