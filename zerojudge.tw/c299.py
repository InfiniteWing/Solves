while True:
    try:
        s = input()
    except EOFError:
        break
    l = []
    for i, c in enumerate(s.split()):
        if(i == 0):
            continue
        l.append(int(c))
    ls = sorted(l)
    ans = True
    for i in range(len(ls)-1):
        if(ls[i+1] - ls[i] != 1):
            ans = False
            break
    if(ans):
        print('{} {} yes'.format(ls[0],ls[len(ls)-1]))
    else:
        print('{} {} no'.format(ls[0],ls[len(ls)-1]))

			