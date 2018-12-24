def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for _ in range(n):
            s = input()
            l = 0
            ans = 0
            for c in s.strip():
                if(c == '('):
                    l += 1
                else:
                    if(l == 0):
                        ans = -1
                        break
                    else:
                        l -= 1
                        ans +=1
            print(ans) if (ans > 0 and l == 0) else print(0)
main()