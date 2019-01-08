from math import gcd
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        if(n == 0): break
        records = {}
        for _ in range(n):
            arr = input().split()
            arr.sort()
            arr = ','.join(arr)
            if(arr not in records):
                records[arr] = 0
            records[arr] += 1
        max_v = 0  
        for k, v in records.items():
            if(v > max_v): max_v = v
        ans = 0
        for k, v in records.items():
            if(v == max_v): ans += v
        print(ans)
main()