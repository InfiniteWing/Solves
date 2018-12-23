def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        o, e, a = float(s.split()[0]),float(s.split()[1]),float(s.split()[2])
        if(o == 0 and e == 0 and a == 0):
            break
        m = o / e
        f = a / m
        print('{0:.2f}'.format(round(m,2)),'{0:.2f}'.format(round(f,2)))
main()