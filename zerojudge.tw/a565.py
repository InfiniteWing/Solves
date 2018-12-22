from sys import stdin, stdout
import os

lines = os.read(0, 35000000)
size = os.fstat(0).st_size
ptr = 35000000
os.lseek(0, ptr, 0)
while(ptr < size):
    ptr += 35000000
    lines += os.read(0,35000000)
    os.lseek(0, ptr, 0)
for s in lines.decode().splitlines():
    if(s.isdigit()):
        continue
    ans = 0
    l = 0
    for c in s:
        if(c == 'p'):
            l += 1
        elif(c == 'q'):
            if(l > 0):
                l -= 1
                ans += 1
    print(ans)
            