def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for i in range(n+1):
            print('2^{} = {}'.format(i,pow(2,i)))
main()