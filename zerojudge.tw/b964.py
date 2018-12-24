def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        
        f = []
        p = []
        s = [int(a) for a in input().split()]
        for v in s:
            if(v>=60):
                p.append(v)
            else:
                f.append(v)
        f.sort()
        p.sort()
        s.sort()
        f = [str(a) for a in f]
        p = [str(a) for a in p]
        s = [str(a) for a in s]
        print(' '.join(s))
        print(f[-1]) if len(f)>0 else print('best case')
        print(p[0]) if len(p)>0 else print('worst case')
        
main()