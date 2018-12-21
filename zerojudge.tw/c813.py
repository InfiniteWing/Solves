def f(a):
    sum = 0
    for c in a:
        sum += int(c)
    if(sum < 10):
        return sum
    else:
        return f(str(sum))
while True:
    try:
        n = input()
    except EOFError:
        break
    if(int(n) == 0):
        break
    print(f(n))

			