def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        if(s == 'END'):
            break
        acronym = []
        for c in s.split():
            acronym.append(c[0].upper())
        print(''.join(acronym),s.split()[-1])
main()