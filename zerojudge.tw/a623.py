def f(n):
    return 1 if n == 1 else n*f(n-1)

def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        dp = [f(i) for i in range(1,30)]
        n, m = int(s.split()[0]),int(s.split()[1])
        a = int(dp[n-1]/dp[m-1]/dp[n-m-1])
        print(a) if a > 0 else print(1)
main()