def main():
    while True:
        s = '猴雞狗豬鼠牛虎兔龍蛇馬羊'
        try:
            n = int(input())
        except EOFError:
            break
        n += 100 if n < 0 else 99
        print(s[n%12])
main()