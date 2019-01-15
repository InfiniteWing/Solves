from math import pow
def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        tmp = 0
        for i, c in enumerate(s):
            if(c == '1'): tmp += pow(-2, len(s)-i-1)
        print(int(tmp))
main()