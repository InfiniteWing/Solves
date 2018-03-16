while 1:
    try:
        s = input()
    except:
        break
    n = int(s.replace('-',''))
    m = s.count('-')
    if(m%2==0):
        print(n)
    else:
        print(-n)