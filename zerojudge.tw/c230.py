while True:
    try:
        n = input()
    except EOFError:
        break
    trees = {}
    for _ in range(int(n)):
        s = input()
        x, y, h = int(s.split()[0]), int(s.split()[1]), int(s.split()[2])
        trees[x*y] = h
    keylist = trees.keys()
    keylist = sorted(keylist)
    max = 0
    highest = trees[keylist[0]]
    for i in range(1,len(keylist)):
        if(highest - trees[keylist[i]] > max):
            max = highest - trees[keylist[i]]
        elif(trees[keylist[i]] > highest):
            highest = trees[keylist[i]]
    print(max)