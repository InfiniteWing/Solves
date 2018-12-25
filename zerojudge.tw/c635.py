def main():
    while True:
        try:
            s = input().split(',')
        except EOFError:
            break
        
        if(len(s) == 1):
            print(s[0])
        else:
            ol = [int(a) for a in s[::2]]
            el = [int(a) for a in s[1::2]]
            ol.sort()
            el.sort()
            nl = []
            for i in range(len(ol)):
                nl.append(str(ol[i]))
                if(i < len(el)):
                    nl.append(str(el[i]))
            print(','.join(nl))
main()