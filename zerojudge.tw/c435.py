from sys import stdin
def main():
    while True:
        try:
            n = int(stdin.readline())
        except EOFError:
            break
        except ValueError:
            break
        arr = stdin.readline().split()
        _min = 999999999999
        _max = -999999999999
        for v in arr:
            v = int(v)
            if(v < _min): _min = v
            if(v > _max): _max = v
        print(_max-_min)
main()