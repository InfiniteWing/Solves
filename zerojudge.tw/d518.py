while True:
    try:
        n=int(input())
    except EOFError:
        break
    index=1
    m = {}
    for i in range(n):
        s = input()
        s = s.rstrip()
        if s not in m:
            m[s] = index
            index = index+1
            print('New! {}'.format(m[s]))
        else:
            print('Old! {}'.format(m[s]))
            