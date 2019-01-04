from sys import stdin, stdout
def main():
    arr = stdin.readlines()
    if(len(arr) == 1):
        arr = arr[0].split()
    n = int(arr[0])
    s = arr[1]
    out = ''
    tc = s[0]
    count = 0
    for i in range(n):
        c = s[i]
        if(c != tc): 
            out+=str(count)+tc
            tc = c
            count = 1
        else:
            count += 1
    out+=str(count)+tc
    stdout.write(out+'\n') if len(out) < n else stdout.write(s+'\n')
main()