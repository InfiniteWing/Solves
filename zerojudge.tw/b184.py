from math import sqrt
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        dp = [0 for i in range(101)]
        for _ in range(n):
            arr = input().split()
            v, p = int(arr[0]), int(arr[1])
            for i in range(100,v-1,-1):
                dp[i] = max(dp[i-v]+p, dp[i])#放或不放
        print(dp[100])
main()