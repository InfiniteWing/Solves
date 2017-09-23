def is_leap(y):
    if(y%400==0):
        return True
    return (y%100!=0 and y%4==0)
def is_huluculu(y):
    return (y%15==0)
def is_bulukulu(y):
    return (y%55==0 and is_leap(y))

n=0
while True:
    try:
        y=int(input())
    except EOFError:
        break
    
    if(n>0):
        print()
    check=False
    if(is_leap(y)):
        check=True
        print("This is leap year.")
    if(is_huluculu(y)):
        check=True
        print("This is huluculu festival year.")
    if(is_bulukulu(y)):
        check=True
        print("This is bulukulu festival year.")
    if(not check):
        print("This is an ordinary year.")
    
        