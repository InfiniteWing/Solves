while True:
    try:
        s1 = input()
    except EOFError:
        break
    
    s2 = ''
    for i in range(len(s1), 0 , -1):
        s2 += s1[i-1]
        
    n = int(s1) + int(s2)
    print(n)