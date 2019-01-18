def dfs(ans, dps, i, n, now, now_dps, need):
    if(i == n):
        if(need == now):
            ans.append(now_dps)
        return
    for j in range(len(dps[i])):
        now += dps[i][j]
        if(now > need):
            return
        dfs(ans, dps, i+1, n, now, now_dps + [str(j)], need)
        now -= dps[i][j]
def main():
    n = int(input())
    arr = [int(a) for a in input().split()]
    need = int(input())
    dps = [[] for _ in range(n)]
    ans = []
    for i, cash_value in enumerate(arr):
        for j in range(int(need/cash_value)+1):
            dps[i].append(cash_value*j)
    dfs(ans, dps, 0, n, 0, [], need)
    for s in ans:
        print('({})'.format(','.join(s)))
            
main()