def dfs(map, m, who):
    dist_i = -1
    dist_move = -1
    times_max = -1
    for i, row in enumerate(map):
        a, b = row
        #print(row)
        dist = b-a
        dist -= 1
        if(dist <= m and dist > 0 and times_max < 0):
            dist_i = i
            dist_move = dist
            times_max = 0
        elif(dist%(m+1) == 1 and times_max < int(dist/(m+1))):
            dist_i = i
            dist_move = 1
            times_max = int(dist/(m+1))
        elif(dist > 0):
            dist_i = i
            dist_move = m
    if(dist_i != -1):
        if(who == 1):
            map[dist_i] = (map[dist_i][0]+dist_move, map[dist_i][1])
            dfs(map, m, 2)
        else:
            map[dist_i] = (map[dist_i][0], map[dist_i][1]-dist_move)
            dfs(map, m, 1)
    else:
        if(who == 1):
            print('Kitty')
        else:
            print('OpenChan')
def main():
    while True:
        try:
            arr = [int(n) for n in input().split()]
        except EOFError:
            break
        n, m = arr[0], arr[1]
        arr = [int(n) for n in input().split()]
        map = []
        for i in range(0,n,2):
            map.append((arr[i],arr[i+1]))
        dfs(map,m,1)
        
main()