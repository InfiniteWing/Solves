import math
while True:
    try:
        n=int(input())
    except EOFError:
        break
    
    b = int(math.sqrt(n))
    print(n-b*b)
    
            