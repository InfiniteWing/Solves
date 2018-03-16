while 1:
    try:
        s = input()
        n,t = int(s.split(' ')[0]),int(s.split(' ')[1])
    except:
        break
    score = [0 for _ in range(t)]
    for _ in range(n):
        s = input()
        s = s.strip()
        for i, r in enumerate(s.strip().split(' ')):
            score[i] += int(r.split(':')[0])*60 + int(r.split(':')[1])
    
    score = sorted(score,reverse=False)
    for v in score:
        print(v)