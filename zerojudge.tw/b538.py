from math import gcd
def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        a, b, c, d, s = int(arr[0]), int(arr[1]), int(arr[2]), int(arr[3]), arr[4]
        if(b < 0):
            a = -a
            b = -b
        if(d < 0):
            c = -c
            d = -d
        a *= d
        c *= b
        b *= d
        if(s == '+'): a += c
        if(s == '-'): a -= c
        if(s == '*'): 
            a *= c
            b *= b
        if(s == '/'): 
            b = c
            if(b < 0):
                a = -a
                b = -b
        if(a == 0): 
            print(0)
        else:
            n = gcd(a, b)
            a = int(a/n)
            b = int(b/n)
            if(a%b == 0):
                print(int(a/b))
            else:
                print('{}/{}'.format(a,b))
            
main()