def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        n = int(input())
        for _ in range(n):
            s2 = input()
            a, b = 0, 0
            count = [0 for _ in range(11)]
            for c in s:
                count[int(c)] += 1
            for i in range(len(s)):
                if(s[i] == s2[i]):
                    a += 1
                    count[int(s[i])] -= 1
            for i in range(len(s)):
                if(count[int(s2[i])] > 0):
                    b += 1
                    count[int(s2[i])] -= 1
            print('{}A{}B'.format(a,b))
            
main()