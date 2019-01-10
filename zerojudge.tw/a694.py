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
        maps = [[0 for _ in range(n)] for _ in range(n)]
        dps = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            arr = stdin.readline().split()
            for j in range(n):
                maps[j][i] = int(arr[j])
                dps[j][i] += maps[j][i]
                if(j > 0): dps[j][i] += dps[j-1][i]
            for j in range(n):
                if(i > 0): dps[j][i] += dps[j][i-1]
        for i in range(n):
            s = []
            for j in range(n):
                s.append(str(dps[j][i]))
            print(' '.join(s))
        for _ in range(m):
            arr = stdin.readline().split()
            x1, y1, x2, y2 = int(arr[0])-1, int(arr[1])-1, int(arr[2])-1, int(arr[3])-1
            ans = dps[y2][x2]
            ans -= dps[y1][x1]
            ans += maps[y1][x1]
            print(ans)
main()