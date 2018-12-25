from sys import stdin
def main():
    names = ['Saber','Lancer','Archer','Rider','Caster','Assassin','Berserker']
    servants = {}
    en = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    for i, c in enumerate(en):
        servants[c] = names[i%len(names)]
    keys = servants.keys()
    counts = {}
    for k in names:
        counts[k] = 0
    lines = stdin.readlines()
    for s in lines:
        for c in s:
            if(c.isalpha()):
                if(c.upper() in keys):
                    counts[servants[c.upper()]] += 1
    max = -1
    max_k = ''
    for k in names:
        if(counts[k] > max):
            max = counts[k]
            max_k = k
    print(max_k)
main()