
while True:
    try:
        n=int(input())
    except EOFError:
        break
    if(n==0):
        break
    s=input()
    n=0
    for d in s.split(' '):
        if(int(d)>1):
            n+=1
            break
    if(n>=1):
        print("Yes")
    else:
        print("No")

