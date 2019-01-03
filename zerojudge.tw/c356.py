from sys import stdin
def main():
    while True:
        try:
            n = int(stdin.readline())
        except EOFError:
            break
        s = stdin.readline()
        out = ''
        index = 0
        for i in range(n):
            out += s[index]
            index += 1+n
        print(out)
main()