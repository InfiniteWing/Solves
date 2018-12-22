def getvalues(s):
    n1 = 0
    n2 = 0
    symbol = ''
    symbols = ['+','-','*','/','%']
    for c in s:
        if(c.isdigit()):
            if(symbol != ''):
                n2 = n2*10 + int(c)
            else:
                n1 = n1*10 + int(c)
        elif(c in symbols):
            symbol = c
    return n1, symbol, n2

while True:
    try:
        n = int(input())
    except EOFError:
        break
    for _ in range(n):
        s = input()
        n1, c, n2 = getvalues(s)
        print(int(eval('{}{}{}'.format(n1,c,n2))))
            