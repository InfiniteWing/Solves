def main():
    # 0 1 2 3 4 5 6 7 8 9
    # 1 0 0 0 0 0 1 0 2 1
    F = [1,0,0,0,0,0,1,0,2,1]
    while True:
        try:
            s = input()
        except EOFError:
            break
        except ValueError:
            break
        ans = 0
        for v in s:
            ans += F[int(v)]
        print(ans)
main()