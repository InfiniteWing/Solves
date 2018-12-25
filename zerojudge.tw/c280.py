def main():
    dp = [1,1,1,2]
    for i in range(100):
        dp.append(dp[i+3]+dp[i+2])
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        print(dp[n])
main()