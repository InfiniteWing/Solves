while True:
    try:
        s = input()
    except EOFError:
        break
    n, m = int(s.split(' ')[0]), int(s.split(' ')[1])
    c = []
    for i in range(n):
        s = input()
        s = [int(n) for n in s.split(' ')]
        c.append(max(s))
    s = sum(c)
    print(s)
    a = []
    for n in c:
        if(s % n == 0):
            a.append(str(n))
    if(len(a) > 0):
        print(' '.join(a))
    else:
        print('-1')