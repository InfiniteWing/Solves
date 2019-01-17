def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        for _ in range(n):
            arr = input().split()
            h1, m1, h2, m2, m3 = int(arr[0]), int(arr[1]), int(arr[2]), int(arr[3]), int(arr[4])
            all_m1 = h1 * 60 + m1
            all_m2 = h2 * 60 + m2
            print('Yes') if all_m1+m3 <= all_m2 else print('No')
main()