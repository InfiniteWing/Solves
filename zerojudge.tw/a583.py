from math import sqrt
def main():
    while True:
        try:
            n = input()
        except EOFError:
            break
        arr = input().split()
        arr = [int(a) for a in arr]
        xs = arr[::2]
        ys = arr[1::2]
        points = []
        for i in range(len(xs)):
            points.append((xs[i],ys[i]))
        distances = []
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                distances.append(sqrt((xs[j]-xs[i])*(xs[j]-xs[i])+(ys[j]-ys[i])*(ys[j]-ys[i])))
        print('{0:0.4f}'.format(min(distances)))
main()