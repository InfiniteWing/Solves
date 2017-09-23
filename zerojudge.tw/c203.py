
def Check(n):
    c=0
    for K in range(int(n/2)):
        k=K+1
        if(n%k==0):
            c+=k
    if(c>n):
        print("abundant")
    elif(c==n):
        print("perfect")
    else:
        print("deficient")
    

while True:
    try:
        t=int(input())
    except EOFError:
        break
    for i in range(t):
        n=int(input())
        Check(n)
