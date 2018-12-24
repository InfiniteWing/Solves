def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        n, m = int(s.split()[0]),int(s.split()[1])
        ans = 0
        ans += 6 + 4 * (m-1)
        n -= 1
        if(n > 0):
            ans += (5 + 3 * (m-1)) * n
        print(ans)            
main()