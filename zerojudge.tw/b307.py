def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for _ in range(n):
            s = input().split()
            a, b, q = int(s[0]),int(s[1]),int(s[2])
            print('SAFE') if a*q%10007 == b*q%10007 else print('BOOM')
main()