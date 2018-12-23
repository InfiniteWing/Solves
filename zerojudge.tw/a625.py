def main():
    dp = [0,1/2]
    for i in range(300):
        dp.append(dp[i+1]+1/(i+3))
    while True:
        try:
            n = float(input())
        except EOFError:
            break
        ans = 1
        for i in range(1,300):
            if(dp[i]>=n):
                ans = i
                break
        print('{} card(s)'.format(ans))
main()