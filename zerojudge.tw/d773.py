def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        s = input().split()
        arr = [int(a) for a in s]
        ans = ""
        for i, v in enumerate(arr):
            if(v == 0):
                continue
            if(v>0):
                if(ans != ""):
                    ans += "+"
            else:
                ans += "-"
            if(i == n-1):
                if(abs(v)!=1):
                    ans += str(abs(v))
                ans += 'x'
            elif(i != n):
                if(abs(v)!=1):
                    ans += str(abs(v))
                ans += 'x^{}'.format(n-i)
            else:
                ans += str(abs(v))
        print(ans)
main()