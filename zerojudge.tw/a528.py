from math import gcd
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        nums = []
        for _ in range(n):
            nums.append(int(input()))
        nums.sort()
        for v in nums:
            print(v)
main()