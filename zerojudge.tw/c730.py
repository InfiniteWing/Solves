def main():
    while True:
        try:
            s = input().split()
        except EOFError:
            break
        apples = [int(a)-30 for a in s]
        n = int(input())
        gets = [1 if a <= n else 0 for a in apples]
        print(sum(gets))
main()