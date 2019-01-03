def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        print(int(n*0.3))
main()