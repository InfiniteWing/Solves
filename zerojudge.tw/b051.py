from functools import cmp_to_key
def numeric_compare(x, y):
    return 1 if int(x+y) >= int(y+x) else -1
def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        nums = s.split()[1:]
        nums = sorted(nums,key=cmp_to_key(numeric_compare))
        nums.reverse()
        print(''.join(nums))
main()