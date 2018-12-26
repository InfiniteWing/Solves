def main():
    records = ''
    while True:
        try:
            s = input()
        except EOFError:
            break
        records += s
        if('E' in s):
            break
    points11 = []
    points21 = []
    p1w11, p2w11, p1w21, p2w21 = 0, 0, 0, 0
    for c in records:
        if(c == 'E'):
            points11.append('{}:{}'.format(str(p1w11),str(p2w11)))
            points21.append('{}:{}'.format(str(p1w21),str(p2w21)))
        else:
            if(c == 'W'):
                p1w11 += 1
                p1w21 += 1
            elif(c == 'L'):
                p2w11 += 1
                p2w21 += 1
            if(p1w11 >= 11 or p2w11 >= 11):
                if(abs(p1w11 - p2w11) >= 2):
                    points11.append('{}:{}'.format(str(p1w11),str(p2w11)))
                    p1w11, p2w11 = 0, 0
            if(p1w21 >= 21 or p2w21 >= 21): 
                if(abs(p1w21 - p2w21) >= 2):
                    points21.append('{}:{}'.format(str(p1w21),str(p2w21)))
                    p1w21, p2w21 = 0, 0
    for s in points11:
        print(s)
    print()
    for s in points21:
        print(s)      
main()