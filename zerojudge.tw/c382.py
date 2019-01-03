def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        a, s, b = int(arr[0]), arr[1], int(arr[2])
        if(s == '+'): print(a+b)
        if(s == '-'): print(a-b)
        if(s == '*'): print(a*b)
        if(s == '/'): print(int(a/b))
main()