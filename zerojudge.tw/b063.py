def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        citys = []
        for _ in range(n):
            arr = input().split()
            x, y = int(arr[0]), int(arr[1])
            citys.append((x,y))
        best_x, best_y = 9999999, 9999999
        best_cost = 99999999999
        for i in range(n):
            x1, y1 = citys[i]
            cost = 0
            for j in range(n):
                x2, y2 = citys[j]
                tmp = abs(x1-x2)+abs(y1-y2)
                cost += tmp
            if(cost < best_cost):
                best_cost = cost
                best_x, best_y  = x1, y1
            elif(cost == best_cost):
                if(x1 < best_x):
                    best_x, best_y  = x1, y1
                elif(x1 == best_x):
                    if(y1 < best_y):
                        best_x, best_y  = x1, y1
                #print(best_x, best_y, best_cost)
        print(best_x, best_y)  
        print(best_cost)        
main()