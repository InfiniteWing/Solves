from math import gcd
def ans(a, b):
    n = a / b
    if(n == 1): return 1
    if(n > 1): return int(ans(a-b,b)*2)
    return int(ans(b, a)+1)
def main():
    '''
    ans = [(-1,-1),(1,1)]
    for i in range(2,1000000):
        if(i % 2 == 0):
            a = ans[int(i/2)][0]+ans[int(i/2)][1]
            b = ans[int(i/2)][1]
            ans.append((a, b))
        else:
            a = ans[i-1][1]
            b = ans[i-1][0]
            ans.append((a, b))
        if(gcd(a,b) > 1): print(a, b)
    '''
    while True:
        try:
            arr = [int(n) for n in input().split()]
        except EOFError:
            break
        try:
            print(ans(arr[0],arr[1]))
        except KeyError:
            print(arr)
        
main()