import array
from sys import stdin, stdout
#m: map
def Explosion(m, x, y):
    if(x < 0 or x >= len(m) or y < 0 or y >= len(m[0])):
        return 0
    if(m[x][y] > 0):
        sum = m[x][y]
        m[x][y] = -1 # checked flag
        sum += Explosion(m, x-1, y)
        sum += Explosion(m, x, y-1)
        sum += Explosion(m, x, y+1)
        sum += Explosion(m, x+1, y)
        return sum
    else:
        return 0
def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        total = 0
        max = 0
        h, w = int(s.split()[0]),int(s.split()[1])
        m = []
        for i in range(h):
            arr = input().split()
            arr = [int(a) for a in arr]
            m.append(arr)
        for i in range(h):
            for j in range(w):
                if(m[i][j] > 0):
                    total += 1
                    part_sum = Explosion(m, i, j)
                    if(part_sum > max):
                        max = part_sum
        print(total)
        print(max)
main()