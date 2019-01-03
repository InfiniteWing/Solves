def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        n, m = int(arr[0]), int(arr[1])
        if(n == 0 and m == 0): break
        words = []
        for _ in range(n):
            words.append(input())
        word = ''.join(words)
        arr = [int(a)-1 for a in input().split()]
        ans = ''
        for v in arr:
            ans += word[v]
        print(ans)
main()