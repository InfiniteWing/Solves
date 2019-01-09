def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        print('Go, {}, go go'.format(s))
main()