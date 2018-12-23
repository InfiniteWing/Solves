def main():
    cn = ['O','B','A','F','G','K','M']
    min = [-.35,-.25,0,.25,.5,1,1.5]
    while True:
        try:
            s = input()
        except EOFError:
            break
        if(s == 'END'):
            break
        n, b, v = s.split()[0], float(s.split()[1]), float(s.split()[2])
        a = b-v
        for i in range(len(cn)):
            if(i == len(cn)-1):
                c = cn[i]
            else:
                if(min[i] <= a < min[i+1]):
                    c = cn[i]
                    break
        print(n,'{0:.2f}'.format(a),c)
main()