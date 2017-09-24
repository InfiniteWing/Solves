en_upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
en_lower="abcdefghijklmnopqrstuvwxyz"
en_all=""

en_maps={}
for i in range(26):
    en_all=en_all+en_upper[i]+en_lower[i]
    en_maps[en_upper[i]]=i*2
    en_maps[en_lower[i]]=i*2+1

stacks=[0 for i in range(52)]

def ans(s,l):
    if(len(s)==l):
        print(s)
        return
    else:
        for i in range(52):
            if(stacks[i]>0):
                stacks[i]-=1
                ans(s+en_all[i],l)
                stacks[i]+=1

while True:
    try:
        n=int(input())
    except EOFError:
        break
    for i in range(n):
        s=input()
        s=s.replace('\r','')
        s=s.replace('\r\n','')
        for i in range(52):
            stacks[i]=0
        for c in s:
            stacks[en_maps[c]]+=1
        ans("",len(s))
        
            