def main():
    while True:
        try:
            s = input().split()
        except EOFError:
            break
        n = int(s[0])
        e = [int(a) for a in s[1:-1]]
        if(n >= len(e)):
            print(sum(e))
        else:
            e.sort(reverse=True)
            print(sum(e[:n]))
main()