def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        if(n == 0):
            break
        s = input().split()
        arr = [int(a) for a in s]
        ans = 0
        while len(arr) > 1:
            arr.sort()
            sum = arr[0]+arr[1]
            ans += sum
            arr = arr[2:]
            arr.append(sum)
        print(ans)
main()