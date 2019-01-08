def explosion(x,y,maps,checks):
    if(checks[x][y] == 1 or maps[x][y] == '0'): return
    checks[x][y] = 1
    if(maps[x][y] == '-'):
        maps[x][y] = '+'
        explosion(x+1,y,maps,checks)
        explosion(x,y+1,maps,checks)
        explosion(x-1,y,maps,checks)
        explosion(x,y-1,maps,checks)

def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        maps = [['0' for _ in range(n+2)] for _ in range(n+2)]
        checks = [[0 for _ in range(n+2)] for _ in range(n+2)]
        for i in range(n):
            arr = input()
            for j in range(len(arr)):
                maps[j+1][i+1] = arr[j]
        arr = input().split()
        x, y = int(arr[0]), int(arr[1])
        explosion(x+1,y+1,maps,checks)
        for i in range(n):
            s = ''
            for j in range(n):
                s += maps[j+1][i+1]
            print(s)
main()