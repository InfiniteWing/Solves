def main():
    # Also can find mid num
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for _ in range(n):
            s = input().split()
            s = s[1:]
            map = [int(a) for a in s]
            ans = 9999999999999
            for i in range(len(map)):
                now = 0
                for j in range(len(map)):
                    now += abs(map[i]-map[j])
                    if(ans < now):
                        break
                if(ans > now):
                    ans = now
            print(ans)
main()