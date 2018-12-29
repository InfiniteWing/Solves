def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        n, m = int(arr[0]), int(arr[1])
        maps = [[0 for _ in range(n+2)] for _ in range(m+2)]
        for y in range(n):
            s = input()
            for x, c in enumerate(s):
                if(c == '*'):
                    maps[x+1][y+1] = 99
        for x in range(1,m+1):
            for y in range(1,n+1):
                if(maps[x-1][y] > 10): maps[x][y] += 1
                if(maps[x-1][y+1] > 10): maps[x][y] += 1
                if(maps[x-1][y-1] > 10): maps[x][y] += 1
                if(maps[x+1][y] > 10): maps[x][y] += 1
                if(maps[x+1][y+1] > 10): maps[x][y] += 1
                if(maps[x+1][y-1] > 10): maps[x][y] += 1
                if(maps[x][y-1] > 10): maps[x][y] += 1
                if(maps[x][y+1] > 10): maps[x][y] += 1
        for y in range(1,n+1):
            out = ''
            for x in range(1,m+1):
                if(maps[x][y]>10):
                    out += '*'
                else:
                    out += str(maps[x][y])
            print(out)
main()