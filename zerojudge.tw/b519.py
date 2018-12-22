def continuous(arr):
    for i in range(13):
        if(arr[i] == 1):
            if(i == 0):
                return arr[12]&arr[11]&arr[10]&arr[9] or arr[i+1]&arr[i+2]&arr[i+3]&arr[i+4]
            else:
                return arr[i+1]&arr[i+2]&arr[i+3]&arr[i+4]

while True:
    try:
        n = int(input())
    except EOFError:
        break
    for _ in range(n):
        s = input()
        cards = [int(m) for m in s.split()]
        points = [0 for _ in range(13)]
        colors = [0 for _ in range(4)]
        for p in cards:
            p = p-1
            points[p%13] += 1
            colors[int(p/13)] += 1
        if(4 in points):
            print(6)
        elif(3 in points and 2 in points):
            print(5)
        elif(3 in points):
            print(3)
        elif(2 in points):
            c = 0
            for v in points:
                if(v == 2):
                    c += 1
            if(c == 2):
                print(2)
            else:
                print(1)
        elif(continuous(points)):
            if(5 in colors):
                print(7)
            else:
                print(4)
        else:
            print(0)