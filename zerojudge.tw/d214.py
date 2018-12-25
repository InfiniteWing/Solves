def main():
    T = []
    P = []
    H = []
    for i in range(1,100000):
        T.append(int(i*(i+1)/2))
        P.append(int(i*(3*i-1)/2))
        H.append(int(i*(2*i-1)))
    #print(T[:5])
    #print(P[:5])
    #print(H[:5])
    map = {}
    for v in T:
        map[v] = 1
    for v in P:
        if(v in map):
            map[v] += 1
    for v in H:
        if(v in map):
            map[v] += 1
    i = 0
    for k, count in map.items():
        if(count == 3):
            i += 1
            if i == 3: print(k) 
main()