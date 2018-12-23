import array
from sys import stdin, stdout
def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        n, r = int(s.split()[0]),int(s.split()[1])
        teams = {}
        for _ in range(r):
            try:
                s = input()
            except EOFError:
                break
            a, b = s.split()[0], s.split()[1]
            if(a not in teams):
                teams[a] = []
            if(b not in teams[a]):
                teams[a].append(b)
        for k, v in teams.items():
            if(len(v) == n-1):
                print(k)
                break
main()