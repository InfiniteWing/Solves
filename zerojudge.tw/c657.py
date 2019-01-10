def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        ans = 0
        ans_c = ''
        n = 0
        tmp = ''
        for c in s:
            if(c != tmp):
                if(n > ans):
                    ans = n
                    ans_c = tmp
                n = 1
                tmp = c
            else:
                n += 1
        if(n > ans):
            ans = n
            ans_c = tmp
        print(ans_c,ans)
main()