def main():
    dp = [0]
    c = 0
    for i in range(1,1000):
        for j in range(i):
            dp.append(dp[c]+i)
            c += 1
            if(len(dp)>10002):
                break
        if(len(dp)>10002):
            break
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        print(dp[n])
main()