def dfs(n):
    total = 0
    if(int(n[0]) >= 2):
        for i in range(1,int(int(n[0])/2)+1):
            total += 1
            #print('{}{}'.format(str(i),n))
            total += dfs('{}{}'.format(str(i),n))
        return total
    else:
        return total


def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        print(dfs(s)+1)
main()