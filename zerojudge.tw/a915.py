def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        arrs = []
        for _ in range(n):
            arr = input().split()
            arrs.append((int(arr[0]), int(arr[1])))
        arrs = sorted(arrs, key=lambda tup: (tup[0],tup[1]) )
        for v in arrs:
            a, b = v
            print(a,b)
main()