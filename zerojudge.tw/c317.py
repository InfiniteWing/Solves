def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for _ in range(n):
            arr = input().split()
            x, a, b = int(arr[0]), int(arr[1]), int(arr[2])
            if(b > a): a, b = b, a
            ans = -1
            for an in range(int(x/a), -1, -1):
                if( (x-an*a)%b == 0):
                    ans = an+int((x-an*a)/b)
                    break
            print(ans)
main()