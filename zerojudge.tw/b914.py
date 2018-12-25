from sys import stdin
def main():
    lines = stdin.readlines()
    all = 0
    j = 0
    sum = 0
    for i, s in enumerate(lines):
        if(j == 0):
            if(i > 0):
                print(int(sum/all+0.5))
            all = int(s)
            j = all
            sum = 0
        else:
            j -= 1
            sum += int(s)
    print(int(sum/all+0.5))
main()