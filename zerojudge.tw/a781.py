def main():
    c = False
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        if(n == 0):
            continue
        if(c):
            print()
        t1 = []
        t2 = []
        for _ in range(4):
            for i in range(n):
                t1.append('#')
                t2.append('.')
            for i in range(n):
                t1.append('.')
                t2.append('#')
        for _ in range(4):
            for i in range(n):
                print(''.join(t1))
            for i in range(n):
                print(''.join(t2))
        c = True
main()