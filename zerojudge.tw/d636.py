# 費馬小定理
# https://zh.wikipedia.org/wiki/%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86
# https://zh.wikibooks.org/zh-tw/%E5%88%9D%E7%AD%89%E6%95%B8%E8%AB%96/%E5%90%8C%E9%A4%98

def main():
    while True:
        try:
            arr = input().split()
        except EOFError:
            break
        a, n = int(arr[0]), int(arr[1])
        n = n % 10006
        print(a**n%10007)
main()