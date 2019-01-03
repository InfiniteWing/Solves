def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for i in range(n-1,-1,-1):
            ans = ''
            for _ in range(i):
                ans += '_'
            for _ in range(n*2-1-i*2):
                ans += '*'
            for _ in range(i):
                ans += '_'
            print(ans)
main()