def main():
    s = input()
    records = {}
    if(len(s.split()) > 1):
        s = s.split()
        s = s[1:]
        for i in range(0, len(s), 2):
            name, type = s[i], s[i+1]
            if(name not in records):
                records[name] = []
            records[name].append(type)
    else:
        n = int(s)
        for _ in range(n):
            arr = input().split()
            name, type = arr[0], arr[1]
            if(name not in records):
                records[name] = []
            records[name].append(type)
    ac = 0
    spike = 0
    for k, v in records.items():
        if(v[-1] == 'AC'): spike += 1
        if('AC' in v): ac += 1
    print('{}%'.format(int(spike*100/ac)))
main()