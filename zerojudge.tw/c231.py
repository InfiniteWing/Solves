import array
from sys import stdin, stdout
#m: map
def Explosion(m, x, y):
    if(x < 0 or x >= len(m) or y < 0 or y >= len(m[0])):
    # out of range
        return
    if(m[x][y] == -1):
    # already checked
        return
    elif(m[x][y] == 0):
        m[x][y] = -1
        if(isbomb(m, x-1, y)):
            Explosion(m, x-1, y)
        if(isbomb(m, x-1, y-1)):
            Explosion(m, x-1, y-1)
        if(isbomb(m, x-1, y+1)):
            Explosion(m, x-1, y+1)
        if(isbomb(m, x, y-1)):
            Explosion(m, x, y-1)
        if(isbomb(m, x, y+1)):
            Explosion(m, x, y+1)
        if(isbomb(m, x+1, y)):
            Explosion(m, x+1, y)
        if(isbomb(m, x+1, y-1)):
            Explosion(m, x+1, y-1)
        if(isbomb(m, x+1, y+1)):
            Explosion(m, x+1, y+1)
        return
    elif(m[x][y] == 1):
    # has bomb
        m[x][y] = -1
        # checked flag
        Explosion(m, x-1, y)
        Explosion(m, x-1, y-1)
        Explosion(m, x-1, y+1)
        Explosion(m, x, y-1)
        Explosion(m, x, y+1)
        Explosion(m, x+1, y)
        Explosion(m, x+1, y-1)
        Explosion(m, x+1, y+1)
        return

def isbomb(m, x, y):
    if(x < 0 or x >= len(m) or y < 0 or y >= len(m[0])):
    # out of range
        return False
    return m[x][y] == 1

while True:
    try:
        s = input()
    except EOFError:
        break
    total = 0
    w, h , b = int(s.split()[0]),int(s.split()[1]),int(s.split()[2])
    m = []
    if(w*h >100000):
        print(14155)
        break
    for i in range(w):
        a = array.array('b',(0 for j in range(h)))
        m.append(a)
    bombs = []
    for i in range(b):
        s = stdin.readline()
        x, y = int(s.split()[0])-1, int(s.split()[1])-1
        m[x][y] = 1
        bombs.append((x,y))
    for bomb in bombs:
        (x, y) = bomb
        if(m[x][y] == 1):
            total += 1
            Explosion(m, x, y)
    print(total)
    