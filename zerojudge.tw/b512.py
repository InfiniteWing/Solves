def main():
    d1 = {}
    ans = 0
    arr = input().split()
    for s in arr:
        i, v = int(s.split(':')[0]), int(s.split(':')[1])
        d1[i] = v
    arr = input().split()
    for s in arr:
        i, v = int(s.split(':')[0]), int(s.split(':')[1])
        if(i in d1):
            ans += d1[i] * v
    print(ans)
            
main()