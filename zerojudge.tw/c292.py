def cal(map, result, x, y, d, step, round):
    if(len(map)*len(map) == len(result)):
        return result
    if(len(result)+step > len(map)*len(map)):
        step -= 1
    #print('result=',result)
    if(d == 0):
        for i in range(x-1,x-step-1,-1):
            result.append(map[i][y])
        if(round == 1):
            return cal(map, result , x-step, y, 1, step, 2)
        else:
            return cal(map, result , x-step, y, 1, step+1, 1)
    if(d == 1):
        for i in range(y-1,y-step-1,-1):
            result.append(map[x][i])
        if(round == 1):
            return cal(map, result , x, y-step, 2, step, 2)
        else:
            return cal(map, result , x, y-step, 2, step+1, 1)
    if(d == 2):
        for i in range(x+1,x+step+1):
            result.append(map[i][y])
        if(round == 1):
            return cal(map, result , x+step, y, 3, step, 2)
        else:
            return cal(map, result , x+step, y, 3, step+1, 1)
    if(d == 3):
        for i in range(y+1,y+step+1):
            result.append(map[x][i])
        if(round == 1):
            return cal(map, result , x, y+step, 0, step, 2)
        else:
            return cal(map, result , x, y+step, 0, step+1, 1)
        

def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        d = int(input())
        map = [[0 for _ in range(n)] for _ in range(n)]
        for y in range(n):
            s = input().split()
            for x in range(n):
                map[x][y] = s[x]
        result = cal(map,[map[int(n/2)][int(n/2)]],int(n/2),int(n/2),d,1,1)
        print(''.join(result))
main()