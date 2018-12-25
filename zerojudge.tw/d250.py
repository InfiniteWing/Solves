def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        arr = [int(a) for a in s]
        print(45 - sum(arr))       
main()