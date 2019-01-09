def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        arr = [int(a[::-1]) for a in input().split()]
        arr.sort()
        print(arr[-1])
main()