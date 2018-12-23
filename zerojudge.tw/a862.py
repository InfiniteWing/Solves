def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        v, r = float(s.split()[0])*1000,float(s.split()[1])
        print('{0:.4f}'.format(round(v/r,4)))
main()