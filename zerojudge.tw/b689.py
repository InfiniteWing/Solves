def BFS(maps, started, checked):
    last = []
    for (x, y) in started:
        checked[x][y] = 1
        if(checked[x+1][y] == 0 and maps[x+1][y] == 0):
            last.append((x+1,y))
            checked[x+1][y] = 1
        if(checked[x-1][y] == 0 and maps[x-1][y] == 0):
            last.append((x-1,y))
            checked[x-1][y] = 1
        if(checked[x][y+1] == 0 and maps[x][y+1] == 0):
            last.append((x,y+1))
            checked[x][y+1] = 1
        if(checked[x][y-1] == 0 and maps[x][y-1] == 0):
            last.append((x,y-1))
            checked[x][y-1] = 1
    return last        
    
    return ''.join(decode_arr)
def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        h, w = int(arr[0]), int(arr[1])
        maps = [[1 for _ in range(h+2)] for _ in range(w+2)]
        checked = [[0 for _ in range(h+2)] for _ in range(w+2)]
        started = [(0,0)]
        for y in range(h):
            map = input()
            for x, c in enumerate(map):
                if(c == '.'):
                    maps[x+1][y+1] = 0
                    if(x == 0 or x == w-1 or y == 0 or y == h-1):
                        started = [(x+1,y+1)]
        for step in range(10000):
            last = BFS(maps, started, checked)
            if(len(last) == 0):
                x,y = started[0][0], started[0][1]
                print(y,x)
                break
            started = last
main()