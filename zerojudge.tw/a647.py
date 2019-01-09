from decimal import *
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for _ in range(n):
            arr = input().split()
            a, b = Decimal(arr[0]), Decimal(arr[1])
            b = b-a
            dif = b/a*100
            #print(dif)
            dif2 = int((int(dif*1000)+5)/10)/100 if dif > 0 else int((int(dif*1000)-5)/10)/100
            #print(dif2)
            if(dif>=10 or dif<=-7):
                print('{0:0.2f}% dispose'.format(dif2))
            else:
                if(round(dif,2) == 0):
                    print('0.00% keep'.format(dif2))
                else:
                    print('{0:0.2f}% keep'.format(dif2))
main()