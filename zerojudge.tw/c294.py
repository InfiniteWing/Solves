def Ans(s):
    l = [int(n) for n in s.split(' ')]
    l.sort()
    a, b, c = l[0], l[1], l[2]
    print(a, b, c)
    if(a + b <= c):
        print('No')
    elif(a * a + b * b < c * c):
        print('Obtuse')
    elif(a * a + b * b == c * c):
        print('Right')
    elif(a * a + b * b > c * c):
        print('Acute')
    
while True:
    try:
        s = input()
    except EOFError:
        break
    Ans(s)