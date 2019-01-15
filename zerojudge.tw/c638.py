def main():
    s1 = '甲乙丙丁戊己庚辛壬癸'
    s2 = '子丑寅卯辰巳午未申酉戌亥'
    s1 = [s for s in s1]
    s2 = [s for s in s2]
    ans = {}
    a1 = 6
    a2 = 8
    for y in range(1800,2019):
        ans[y] = s1[a1]+s2[a2]
        a1 += 1
        a2 += 1
        if(a1 > 9): a1 = 0
        if(a2 > 11): a2 = 0
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        print(ans[n])
main()