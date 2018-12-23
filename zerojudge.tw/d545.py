import array
from sys import stdin, stdout
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        s = input()
        color_p = {'S':0.4,'H':0.3,'D':0.2,'C':0.1}
        color = ''
        cards = {}
        for c in s.split():
            if(c.isdigit()):
                cards[int(c)+color_p[color]] = '{} {}'.format(color,c)
            else:
                color = c
        keys = sorted(cards.keys(),reverse=True)
        n = int(input())
        print(cards[keys[n-1]])
main()