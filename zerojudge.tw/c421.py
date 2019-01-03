def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for i in range(n):
            ans = ''
            for _ in range(i+1):
                ans += '*'
            print(ans)
main()