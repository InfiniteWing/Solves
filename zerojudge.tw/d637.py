def main():
    n = int(input())
    DP = [0 for _ in range(101)]
    for _ in range(n):
        arr = input().split()
        a, b = int(arr[0]), int(arr[1])
        for i in range(100,a-1,-1):
            if(DP[i] < DP[i-a] + b): DP[i] = DP[i-a] + b
    print(DP[100])
main()