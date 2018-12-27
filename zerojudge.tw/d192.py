def josephus_recursion(n, k):
    # https://zh.wikipedia.org/wiki/约瑟夫斯问题
	return (josephus_recursion(n - 1, k) + k) % n if n > 1 else 0
def josephus(n, k):
    s = 0;
    for i in range(2, n+1):
        s = (s + k) % i;
    return s;
def main():
    n = int(input())
    for case in range(n):
        s = input().split()
        n, k = int(s[0]), int(s[1])
        '''
        # TLE
        mans = [str(i+1) for i in range(n)]
        i = k-1
        while(len(mans) > 1):
            i %= len(mans)
            #print('kill',i+1)
            del(mans[i])
            #print('alive:',','.join(mans))
            i += k-1
        '''
        print('Case {}: {}'.format(case+1,josephus(n,k)%n+1))
main()