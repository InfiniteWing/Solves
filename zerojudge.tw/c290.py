def Ans(s):
    is_odd = True
    A = 0
    B = 0
    
    for i in range(len(s)):
        c = s[len(s)-i-1]
        if(is_odd):
            A += int(c)
        else:
            B += int(c)
        is_odd = not is_odd
    return abs(A - B)

while True:
    try:
        s=input()
    except EOFError:
        break
    print(Ans(s))