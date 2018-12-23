import array
from sys import stdin, stdout
def getkey(keys, key):
    if(len(keys) == len(key)+1):
        return key
    elif(key == ''):
        return getkey(keys,str(int(keys[-1]>=keys[-2])))
    else:
        return getkey(keys,str(int(abs(keys[-len(key)]-keys[-len(key)-1])>=keys[-len(key)-2]))+key)
    
def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        n, m = int(s.split()[0]),int(s.split()[1])
        secret = input()
        secret = ''.join(secret.split())
        for _ in range(n):
            s = input()
            keys = [int(v) for v in s.split()]
            if(getkey(keys,'') == secret):
                print(s)
main()