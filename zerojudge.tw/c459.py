import math

def basen2base10(n, b):
    if(b == 10):
        return n
    total = 0
    for i, c in enumerate(str(n)):
        total += int(c) * math.pow(b, len(str(n))-1-i)
    return int(total)
    

while True:
    try:
        s = input()
    except EOFError:
        break
    b, n = int(s.split()[0]), int(s.split()[1])
    
    chkn1 = basen2base10(n, b)
    chkn2 = 0
    for c in str(n):
        chkn2 += math.pow(int(c),len(str(n)))
    if(chkn1 == chkn2):
        print('YES')
    else:
        print('NO')
        