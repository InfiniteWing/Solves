def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        for i in range(len(s)):
            w = []
            for j in range(len(s)):
               w.append(s[j].upper()) if i == j else w.append(s[j].lower())
            if(s[i] == ' '):
                continue
            print(''.join(w))
main()