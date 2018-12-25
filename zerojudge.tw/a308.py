def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        target = s.lower()
        s2 = input().lower()
        flag = True
        pos = []
        for i, c in enumerate(s2):
            if(c == ' '):
                flag = True
            else:
                if(flag):
                    if(s2[i:i+len(target)] == target and s2[i+len(target):i+len(target)+1] == ' '):
                        pos.append(i)
                    flag = False
                else:
                    continue
        print(len(pos),pos[0]) if len(pos) > 0 else print(-1)
main()