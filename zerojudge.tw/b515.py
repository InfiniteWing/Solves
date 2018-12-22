codes = {
'.-':'A',
'-...':'B',
'-.-.':'C',
'-..':'D',
'.':'E',
'..-.':'F',
'--.':'G',
'....':'H',
'..':'I',
'.---':'J',
'-.-':'K',
'.-..':'L',
'--':'M',
'-.':'N',
'---':'O',
'.--.':'P',
'--.-':'Q',
'.-.':'R',
'...':'S',
'-':'T',
'..-':'U',
'...-':'V',
'.--':'W',
'-..-':'X',
'-.--':'Y',
'--..':'Z'}

while True:
    try:
        n = int(input())
    except EOFError:
        break
    for _ in range(n):
        s = input()
        sn = []
        for w in s.split():
            sn.append(codes[w])
        print(''.join(sn))
        