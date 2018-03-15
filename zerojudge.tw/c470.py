while True:
    try:
        n = int(input())
    except EOFError:
        break
    m1 = 0
    m2 = 0
    ss = input()
    for i, s in enumerate(ss.split()):
        s = int(s)
        if(i%2==0):
            m1 += s
        else:
            m2 += s
    print(max(m1,m2))