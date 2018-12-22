from sys import stdin, stdout
import os,itertools

start = False
ans = 0
l = 0
newin = os.fdopen(stdin.fileno(), 'rb', 8192 * 1024)

for line in fo.readlines():
    record = os.read(newin.fileno(), 1024 * 1024)
    if not record:
        break
    for c in record:
        if(c == 46):
            pass
        if(c in [112,113,46]):
            start = True
            if(c == 112):
                l += 1
            elif(c == 113):
                if(l > 0):
                    l -= 1
                    ans += 1
        elif(c not in [112,113,46,48,49,50,51,52,53,54,55,56,57]):
            if(start):
                print(ans)
                start = False
                ans = 0
                l = 0