def main():
    while True:
        try:
            a = input()
        except EOFError:
            break
        c = input()
        b = input()
        print(int(eval(a+c+b)))
main()