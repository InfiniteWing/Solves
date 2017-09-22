###
### This code works on short input string
### For long string input... It crash
###
import sys
while True:
    s = sys.stdin.readline()
    if s == '':
        break
        
    d=s.split(' ')
    n=int(d[0])
    m=int(d[1])
    
    datas=[]
    check=0
    
    while True:
        if(check==n):
            break
        s = sys.stdin.readline()
        try:
            d=s.split(' ')
            for num in d:
                datas.append(int(num))
            check+=len(d)
        except:
            pass
    for i in range(m):
        s = sys.stdin.readline()
        d=s.split(' ')
        t=int(d[0])
        l=int(d[1])
        l=l-1
        r=int(d[2])
        if(t==1):
            v=int(d[3])
            for j in range(l,r):
                datas[j]=max(datas[j],v)
        else:
            print(sum(datas[l:r]))