from math import gcd
def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        try:
            a, b = int(arr[0]), int(arr[1])
            print(gcd(a,b))
        except IndexError:
            break
main()