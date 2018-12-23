def main():
    num = [1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900]
    texts = 'ABGDE#ZYHIKLMNXOPQRSTUFC$W3'
    text2num = {}
    for i in range(len(num)):
        text2num[texts[i]] = num[i]
    while True:
        try:
            s = input()
        except EOFError:
            break
        if(s == '.'):
            break
        n = 0
        for i in range(len(s)):
            n += text2num[s[i]]
        print(n)
main()