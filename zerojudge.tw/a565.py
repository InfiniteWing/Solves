from sys import stdin, stdout
import os,itertools

# 2.4s
def main():
    n = int(input())
    for _ in range(n):
        line = input()
        ans = 0
        l = 0
        for c in line:
            if(c == '.'):
                pass
            elif(c == 'p'):
                l += 1
            elif(c == 'q'):
                if(l > 0):
                    l -= 1
                    ans += 1
        print(ans)
'''
#TLE
def main():
    start = False
    ans = 0
    l = 0
    while True:
        record = os.read(0, 34000000)
        if not record:
            break
        for c in record:
            if(c not in [112,113,46,48,49,50,51,52,53,54,55,56,57]):
                if(start):
                    print(ans)
                    start = False
                    ans = 0
                    l = 0
            elif(c in [112,113,46]):
                start = True
                if(c == 112):
                    l += 1
                elif(c == 113):
                    if(l > 0):
                        l -= 1
                        ans += 1
'''
'''
# 2.1s
def main():
    newin = os.fdopen(stdin.fileno(), 'rb', 37100000 )
    for line in newin.readlines():
        if(line[0] in [48,49,50,51,52,53,54,55,56,57]):
            continue
        ans = 0
        l = 0
        for c in line:
            if(c == 46):
                pass
            elif(c == 112):
                l += 1
            elif(c == 113):
                if(l > 0):
                    l -= 1
                    ans += 1
        print(ans)
  
'''
'''
#2.3 s   
def main():
    #newin = os.fdopen(stdin.fileno(), 'rb', 35000000 )
    for line in stdin.readlines():
        if(ord(line[0]) in [48,49,50,51,52,53,54,55,56,57]):
            continue
        ans = 0
        l = 0
        for c in line:
            if(c == '.'):
                pass
            elif(c == 'p'):
                l += 1
            elif(c == 'q'):
                if(l > 0):
                    l -= 1
                    ans += 1
        print(ans)  
'''
main()