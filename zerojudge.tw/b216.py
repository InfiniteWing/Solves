def main():
    box = [0 for _ in range(10)]
    for _ in range(9):
        s = input().split()
        x, y = int(s[0]),int(s[1])
        x = int(x/10) if x % 10 != 0 and 0 < x < 30  else -1
        y = int(y/10) if y % 10 != 0 and 0 < y < 30 else -1
        if(x >= 0 and y >= 0):
            box[1+x+(2-y)*3] = 1
    pts = 0
    line = 0
    line += 1 if box[1]&box[2]&box[3] else 0
    line += 1 if box[4]&box[5]&box[6] else 0
    line += 1 if box[7]&box[8]&box[9] else 0
    line += 1 if box[1]&box[4]&box[7] else 0
    line += 1 if box[2]&box[5]&box[8] else 0
    line += 1 if box[3]&box[6]&box[9] else 0
    pts += 2 if box[5] else 0
    pts += 5 if box[2] else 0
    pts += 5 if box[4] else 0
    pts += 5 if box[6] else 0
    pts += 5 if box[8] else 0
    pts += 8 if box[1] else 0
    pts += 8 if box[3] else 0
    pts += 8 if box[7] else 0
    pts += 8 if box[9] else 0
    print(line,pts)
main()