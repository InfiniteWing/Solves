while True:
    try:
        n = int(input())
    except EOFError:
        break
    if(n>0):
        print(1+int((n-1)*2))
    else:
        n = -n
        print(int(n*2))