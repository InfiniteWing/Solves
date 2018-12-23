def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        l, w = int(s.split()[0]),int(s.split()[1])
        print(l*2+w*2)
main()