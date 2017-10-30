while True:
    try:
        s = input()
    except EOFError:
        break
    s = input()
    a = ''
    for c in s:
        if(c.isupper()):
            a += c.lower()
        else:
            a += c.upper()
    print(a)