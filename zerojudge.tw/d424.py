house=[]
last_r=0
for i in range(10001):
    house.append(0)
while True:
    try:
        s=input()
    
        d=s.split(' ')
        l=int(d[0])
        r=int(d[2])-1
        h=int(d[1])
    except:
        break
    
    if(last_r<r):
        last_r=r
    for i in range(l,r+1):
        if(house[i]<h):
            house[i]=h

ans=[]
current=0
for i in range(last_r+1):
    if(house[i]!=current):
        current=house[i]
        ans.append(str(i))
        ans.append(str(house[i]))
ans.append(str(last_r+1))
ans.append('0')
print(' '.join(ans))