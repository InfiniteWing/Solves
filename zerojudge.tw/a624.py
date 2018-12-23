def chk1(pwd):
    return len(pwd)>=8
def chk2(pwd):
    u = False
    l = False
    for c in pwd:
        if(c.isupper()):
            u = True
        if(c.islower()):
            l = True
    return u&l
def chk3(pwd):
    w = False
    m = False
    for c in pwd:
        if(c.isalpha()):
            w = True
        else:
            m = True
    return w&m
def main():
    words = ['WEAK','ACCEPTABLE','GOOD','STRONG']
    while True:
        try:
            s = input()
        except EOFError:
            break
        ptr = 0
        ptr += 1 if chk1(s) else 0
        ptr += 1 if chk2(s) else 0
        ptr += 1 if chk3(s) else 0
        print('This password is {}'.format(words[ptr]))
main()