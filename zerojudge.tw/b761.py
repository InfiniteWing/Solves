def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        print('egg') if n%4 == 0 else print('fat')
main()