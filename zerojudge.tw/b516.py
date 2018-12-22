EN = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
EN_ENCODE = 'DEFGHIJKLMNOPQRSTUVWXYZABC'

EN_ENCODE_MAP = {}
for i in range(len(EN)):
    EN_ENCODE_MAP[EN[i]]= EN_ENCODE[i]

while True:
    try:
        n = int(input())
    except EOFError:
        break
    for _ in range(n):
        s = input()
        sn = []
        for w in s:
            sn.append(EN_ENCODE_MAP[w])
        print(''.join(sn))
        