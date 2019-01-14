def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        records = []
        for _ in range(n):
            records.append(input())
        records.sort()
        for ans in records:
            print(ans)
main()