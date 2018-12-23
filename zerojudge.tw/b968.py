def main():
    while True:
        try:
            g = input()
        except EOFError:
            break
        b = input()
        print('{} and {} sitting in the tree'.format(g,b))
main()