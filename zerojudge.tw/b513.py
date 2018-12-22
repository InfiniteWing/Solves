import math
while True:
    try:
        n = int(input())
    except EOFError:
        break
    
    primes = [2]
    for i in range(3,257):
        flag = True
        for j in range(i,int(math.sqrt(i))):
            if(i%j == 0):
                flag = False
                break
        if(flag):
            primes.append(i)
        
    for _ in range(n):
        a = int(input())
        flag = True
        for prime in primes:
            if(a%prime == 0):
                flag = False
                break
            if(math.sqrt(a)<prime):
                break
        if(flag):
            print('Y')
        else:
            print('N')