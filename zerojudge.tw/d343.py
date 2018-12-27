def isend(cards, now):
    for i in range(6):
        if(cards[i] == 0):
            continue
        points = i+1
        return now+points > 31
def cantkill(cards, now):
    # 26
    pick = False
    for i in range(6):  
        if(cards[i] == 0):
            continue
        if(now+i+1>31):
            break
        cards[i] -= 1
        if(isend(cards, now+i+1)):
            cards[i] += 1
            pick = True
            break
        else:
            cards[i] += 1
    return pick
def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        cards = [4 for _ in range(6)]
        pts = 0
        pi = len(s)
        for c in s:
            cards[int(c)-1] -= 1
            pts += int(c)
        while True:
            if(isend(cards,pts)):
                break
            pick = False
            for i in range(6):  
                if(cards[i] == 0):
                    continue
                if(pts+i+1>31):
                    break
                cards[i] -= 1
                if(isend(cards, pts+i+1)):
                    pts += i+1
                    pick = True
                    break
                else:
                    cards[i] += 1
            if(not pick):
                for i in range(6):
                    if(pts+i+1>31):
                        break
                    if(cards[i] > 0):
                        cards[i] -= 1
                        if(not cantkill(cards, pts+i+1)):
                            pts += i+1
                            pick = True
                            break
                        else:
                            cards[i] += 1
                if(not pick):
                    for i in range(6):  
                        if(cards[i] > 0):
                            cards[i] -= 1
                            pts += i+1
                            break   
            pi += 1
        winner = ['B','A']
        print(s,winner[pi%2])
main()