from math import sqrt
def main():
    primes = [2]
    for i in range(3,44723):
        flag = True
        max = sqrt(i)
        for prime in primes:
            if(prime > max):
                break
            if(i%prime == 0):
                flag = False
                break
        if(flag):
            primes.append(i)
    while True:
        try:
            a = int(input())
        except EOFError:
            break
        for prime in primes:
            if(a%prime == 0):
                print(int(a/prime))
                break
main()