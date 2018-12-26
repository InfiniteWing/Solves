def dfs(n):
    #TLE
    a = int(n/2)
    total = a
    for i in range(1,a+1):
        total += dfs(i)
    return total
def main():
    DP = []
    '''
    10
    110  0
    210  1
    310  1
    410  2
    510  2
    n/2
    1210
    1310
    1410
    2410
    1510
    2510
    12410
    12510
    '''
    for i in range(1003):
        total = int(i/2)
        for j in range(int(i/2)):
            total += DP[j]
            c = int(j/2)
            while(c>1):
                total += DP[c]
                c = int(c/2)
        DP.append(total)
    while True:
        try:
            n = int(input())
            #print(dfs(n)+1)
            print(DP[n+2])
        except EOFError:
            break
            
main()