def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        s += s
        for i in range(int(len(s)/2)):
            print(s[i:i+int(len(s)/2)])
main()