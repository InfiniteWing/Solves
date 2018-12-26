def analyze(s):
    num, total, a, flag, x = -1, 0, 0, '', ''
    for c in s:
        if(c in ['+','-']):
            if(num != -1):
                if(flag == '-'):
                    num = -num
                total += num
            flag = c
            num = -1
        elif(c.isalpha()):
            if num == -1: num = 1
            if(flag == '-'):
                num = -num
            x = c
            a += num
            num = -1
        elif(c.isdigit()):
            if(num == -1):
                num = int(c)
            else:
                num *= 10
                num += int(c)
    if(num != -1):
        if(flag == '-'):
            num = -num
        total += num 
    return a, x, total
def main():
    while True:
        try:
            s = input().split('=')
        except EOFError:
            break
        a1, x1, total1 = analyze(s[0])
        a2, x2, total2 = analyze(s[1])
        if(len(x1) == 0):
            x1 = x2
        result = (total2-total1)/(a1-a2)
        if(result == 0):
            result = 0
        print('{}={}'.format(x1,'{0:0.3f}'.format(round(result,3))))
main()