from sys import stdin
def main():
    while True:
        try:
            arr = stdin.readline().split()
        except EOFError:
            break
        try:
            n, m = int(arr[0]), int(arr[1])
        except IndexError:
            break
        maps = [[0 for _ in range(n+1)] for _ in range(n+1)]
        for i in range(n):
            arr = stdin.readline().split()
            for j in range(n):
                maps[j][i] = int(arr[j])
        for _ in range(m):
            arr = stdin.readline().split()
            x1, y1, x2, y2 = int(arr[0])-1, int(arr[1])-1, int(arr[2])-1, int(arr[3])-1
            ans = 0
            for i in range(x1, x2+1):
                for j in range(y1, y2+1):
                    ans += maps[j][i]
            print(ans)
main()