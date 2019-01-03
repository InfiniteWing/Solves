def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        if(len(arr)<2): break
        h, m = int(arr[0]), int(arr[1])
        all_m = h*60 + m + 150
        if(all_m >= 60*24): all_m -= 60*24
        h, m = int(all_m/60), all_m%60
        print('{}:{}'.format(str(h).zfill(2),str(m).zfill(2)))
main()