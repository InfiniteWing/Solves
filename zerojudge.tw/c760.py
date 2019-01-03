def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        for v in arr:
            v = v[0].upper()+v[1:len(v)]
            print(v)
main()