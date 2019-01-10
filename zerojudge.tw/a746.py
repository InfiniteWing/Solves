def main():
    maps = [[0 for _ in range(500)] for _ in range(500)]
    while True:
        try:
            while True:
                arr = input().split()
                if(len(arr) == 2):
                    break
        except EOFError:
            break
        try:
            n, m = int(arr[0]), int(arr[1])
        except IndexError:
            break
        for i in range(n):
            for j in range(n):
                maps[i][j] = 0
        arr = input().split()
        x1, y1 = int(arr[0]), int(arr[1])
        maps[y1-1][x1-1] = 1
        for _ in range(m-1):
            arr = input().split()
            x2, y2 = int(arr[0]), int(arr[1])
            if(y1 == y2):
                for x in range(min(x1,x2),max(x1,x2)+1):
                    maps[y1-1][x-1] = 1
            else:
                for y in range(min(y1,y2),max(y1,y2)+1):
                    maps[y-1][x1-1] = 1
            x1, y1 = x2, y2
        out = ''
        for _ in range(n+2):
            out += '-'
        print(out)
        for x in range(n):
            s = '|'
            for y in range(n):
                s += ' ' if maps[y][x] == 0 else '*'
            s += '|'
            print(s)
        print(out)
main()