def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for _ in range(n):
            c = int(input())
            cows = []
            for _ in range(c):
                cows.append(int(input()))
            cows.sort()
            print(cows[int((len(cows)-1)/2)])
main()