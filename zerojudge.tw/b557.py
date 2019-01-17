popular_abc = []
def right_triangle():
    for a in range(1,101):
        for b in range(a, 101):
            for c in range(b, 101):
                if(a*a+b*b == c*c):
                    popular_abc.append([a,b,c])
                    #print('[{},{},{}],'.format(a,b,c))

def main():
    right_triangle()
    #print(len(popular_abc))
    n = int(input())
    for _ in range(n):
        s = int(input())
        counts = [0 for _ in range(101)]
        arr = [int(a) for a in input().split()]
        for v in arr:
            counts[v] += 1
        ans = 0
        for abc in popular_abc:
            ans += counts[abc[0]]*counts[abc[1]]*counts[abc[2]]
        print(ans)
            
main()
#right_triangle()