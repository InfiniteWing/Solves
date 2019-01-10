# 1 2 3 4 5 6 7 8 9
# 1 2 3 4 0 1 2 3 4
# 1 0 1 2 0 1 0 1 2
# 0 0 0 0 0 0 0 0 0 
# 1 2 3 4
# 1 0 1 2
# 0 0 0 1
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        ans = 0
        while(n > 0):
            ans += 1 
            center = int((n+1)/2)
            n = n-center
        print(ans)
main()