def main():
    while True:
        key1 = '-mjqhofawcpnsexdkvgtzblryui'
        key2 = '-uzrmatifxopnhwvbslekycqjgd'
        try:
            n = int(input())
        except EOFError:
            break
        for _ in range(n):
            arr = input().split()
            arr = arr[1:]
            if(arr[0].isalpha()):
                sum = 0
                for c in arr:
                    sum += key2.find(c)
                print(sum)
            else:
                out = []
                for c in arr:
                    out += key1[int(c)]
                print(''.join(out))
main()