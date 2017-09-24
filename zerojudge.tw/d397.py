
coins=[10000,5000,2000,1000,500,200,100,50,20,10,5]
dps=[0 for i in range(30001)]

dps[0]=1
    
for i in range(len(coins)):
    for j in range(coins[i],30001):
        dps[j]+=dps[j-coins[i]]

while True:
    try:
        s=input()
    except EOFError:
        break
    d=s.split('.')
    n=int(d[0])*100+int(d[1])
    if(n==0):
        break
    ans=str(dps[n])
    while(len(s)<6):
        s=" "+s
    while(len(ans)<17):
        ans=" "+ans
    ans=s+ans
    print(ans)
    
            