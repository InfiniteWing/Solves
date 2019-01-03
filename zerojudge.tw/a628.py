index = 1
def cal(map, result, x, y, d, step, round):
    global index
    if(len(map)*len(map) == len(result)):
        return result
    if(len(result)+step > len(map)*len(map)):
        step -= 1
    #print('result=',result)
    if(d == 0):
        for i in range(x-1,x-step-1,-1):
            result.append(map[i][y])
            map[i][y] = index
            index += 1
        if(round == 1):
            return cal(map, result , x-step, y, 3, step, 2)
        else:
            return cal(map, result , x-step, y, 3, step+1, 1)
    if(d == 1):
        for i in range(y-1,y-step-1,-1):
            result.append(map[x][i])
            map[x][i] = index
            index += 1
        if(round == 1):
            return cal(map, result , x, y-step, 0, step, 2)
        else:
            return cal(map, result , x, y-step, 0, step+1, 1)
    if(d == 2):
        for i in range(x+1,x+step+1):
            result.append(map[i][y])
            map[i][y] = index
            index += 1
        if(round == 1):
            return cal(map, result , x+step, y, 1, step, 2)
        else:
            return cal(map, result , x+step, y, 1, step+1, 1)
    if(d == 3):
        for i in range(y+1,y+step+1):
            result.append(map[x][i])
            map[x][i] = index
            index += 1
        if(round == 1):
            return cal(map, result , x, y+step, 2, step, 2)
        else:
            return cal(map, result , x, y+step, 2, step+1, 1)
        

def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        map = [[0 for _ in range(n)] for _ in range(n)]
        result = cal(map,[map[int(n/2)][int(n/2)]],int(n/2),int(n/2),2,1,1)
        global index
        index = 1
        for x in range(n):
            out = ''
            for y in range(n):
                if(map[y][x] <10):
                    out += '   '
                elif(map[y][x] <100):
                    out += '  '
                elif(map[y][x] <1000):
                    out += ' '
                out += str(map[y][x])
            print(out)
main()