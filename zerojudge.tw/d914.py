def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        a = [0 for _ in range(19*19)]
        b = [0 for _ in range(19*19)]
        for _ in range(n):
            s = input()
            x, y, c = int(s.split()[0])-1,int(s.split()[1])-1,int(s.split()[2])
            if(c == 0):
                c = -1
            a[x+y*19] = c
        n = int(input())
        for _ in range(n):
            s = input()
            x, y, c = int(s.split()[0])-1,int(s.split()[1])-1,int(s.split()[2])
            if(c == 0):
                c = -1
            b[x+y*19] = c
        ans = 0
        for i in range(19*19):
            ans += abs(a[i]-b[i])
        print(ans)
main()