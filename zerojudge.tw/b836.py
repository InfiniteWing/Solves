def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        n, m = int(arr[0]), int(arr[1])
        if(m == 0):
            print('Go Kevin!!')
            continue
        for i in range(1, 99999999999, m):
            n -= i
            if(n == 0): 
                print('Go Kevin!!')
                break
            if(n < 0):
                print('No Stop!!')
                break     
main()