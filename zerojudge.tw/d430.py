from sys import stdin
def main():
    w = 0
    txt = stdin.detach().readlines()
    for line in txt:
        for word in line.decode('windows-1252').strip().split():
            for c in word:
                if(c.isalpha() or c.isdigit()):
                    w += 1
                    break
    print(w)
main()