def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        n, s = int(arr[0]), arr[1]
        ans = 0
        for i in range(0, len(s)-n-1):
            for j in range(i+1, len(s)):
                left_pattern = s[i:j]
                if(len(left_pattern) > len(s)-j-n):
                    break
                center = s[j:j+n]
                right_pattern = s[j+n:j+n+len(left_pattern)]
                if(left_pattern == right_pattern):
                    ans += 1
                    #print(left_pattern,center,right_pattern)
        print(ans)        
main()