def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        x, y = 0, 0
        for _ in range(n):
            arr = input().split()
            m, d = int(arr[0]), int(arr[1])
            if(m == 0): y += d
            if(m == 1): x += d
            if(m == 2): y -= d
            if(m == 3): x -= d
        print(x,y)
main()