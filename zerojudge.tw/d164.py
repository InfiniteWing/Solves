def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        n, m = int(s.split()[0]),int(s.split()[1])
        cows = []
        for i in range(n):
            cows.append(int(input()))
        cows = cows + cows
        dp = [sum(cows[0:m])]
        for i in range(1,int(len(cows)/2)):
            dp.append(dp[i-1]+cows[i+m-1]-cows[i-1])
        print(max(dp))
main()