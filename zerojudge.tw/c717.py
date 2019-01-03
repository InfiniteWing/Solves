def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        print('{} {}'.format(s,s))
main()