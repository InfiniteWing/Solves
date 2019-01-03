def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        records = {}
        for v in arr:
            if(v not in records):
                records[v] = 0
            records[v] += 1
        for k, v in records.items():
            if(v%3 != 0):
                print(k)
                break
main()