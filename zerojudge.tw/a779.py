from math import sqrt
def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        clean_s = []
        for c in s:
            if(c.isalpha()):
                clean_s.append(c.lower())
            if(c.isdigit()):
                clean_s.append(c)
        clean_s1 = ''.join(clean_s)
        clean_s.reverse()
        clean_s2 = ''.join(clean_s)
        print(s)
        print('-- is a palindrome') if clean_s1 == clean_s2 else print('-- is not a palindrome')            
main()