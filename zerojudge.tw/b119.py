def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        s, t, n = int(arr[0]),int(arr[1]),int(arr[2])
        arr = arr[3:]
        records = [int(a) for a in arr]
        ans = 0
        for i in range(sum(records)):
            discount_rate = 1
            if(i+1 <= t*0.2):
                discount_rate = 0.7
            elif(i+1 <= t*0.4):
                discount_rate = 0.8
            elif(i+1 <= t*0.6):
                discount_rate = 0.9
            ans += int(s*discount_rate+0.5)
        print(int(ans - s*t*0.3))
main()