from math import log
from operator import itemgetter, attrgetter
class Number:
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.c = b * log(a,10)
    def __repr__(self):
        return repr((self.a, self.b, self.c))
def main():
    numbers = []
    while True:
        try:
            s = input().split()
        except EOFError:
            break
        if(s == []):
            break
        a, b = int(s[0]), int(s[1])
        numbers.append(Number(a,b))
    numbers = sorted(numbers, key=attrgetter('c','a'),reverse=True)
    for n in numbers:
        print(n.a,n.b)
main()