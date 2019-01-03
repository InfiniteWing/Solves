def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for i in range(n-1,-1,-1):
            ans = ''
            for j in range(n):
                ans += '*' if(j>=i) else '_'
            print(ans)
main()