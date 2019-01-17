def main():
    ans = [1]
    for i in range(1,502):
        ans.append(i + ans[i-1])
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        print(ans[n-1])
main()