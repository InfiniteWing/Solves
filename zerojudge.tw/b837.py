from sys import stdout
def main():
    while True:
        F = [0,1]
        for i in range(2, 40):
            F.append(F[i-1]+F[i-2])
        try:
            n = int(input())
        except EOFError:
            break
        for i in range(n):
            if(i > 0):
                stdout.write('------\n')
            s = input().split()
            a, b = int(s[0]),int(s[1])
            num = 0
            if(a > b):
                a, b = b, a
            for v in F:
                if(a <= v <= b):
                    print(v)
                    num += 1
                elif(b<v):
                    break
            stdout.write(str(num)+'\n')
main()