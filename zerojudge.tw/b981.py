def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        ans = 0
        if('.' in s):
            s = s.replace('.', ' ')
            s = s.replace('s', '')
            s = [int(a) for a in s.split()]
            ans = s[0]*1000 + s[1]*100
        elif('ms' in s):
            s = s.replace('ms', '')
            s = [int(a) for a in s.split()]
            ans = s[0]
        elif('h' in s and 'm' in s and 's' in s):
            s = s.replace('h', ' ')
            s = s.replace('m', ' ')
            s = s.replace('s', '')
            s = [int(a) for a in s.split()]
            ans = s[0]*1000*60*60 + s[1]*1000*60 + s[2]*1000
        elif('m' in s and 's' in s):
            s = s.replace('m', ' ')
            s = s.replace('s', '')
            s = [int(a) for a in s.split()]
            ans = s[0]*1000*60 + s[1]*1000
        elif('h' in s and 'm' in s):
            s = s.replace('h', ' ')
            s = s.replace('m', '')
            s = [int(a) for a in s.split()]
            ans = s[0]*1000*60*60 + s[1]*1000*60
        elif('hour' in s):
            s = s.replace('hour', '')
            s = [int(a) for a in s.split()]
            ans = s[0]*1000*60*60
        elif('min' in s):
            s = s.replace('min', '')
            s = [int(a) for a in s.split()]
            ans = s[0]*1000*60
        elif('s' in s):
            s = s.replace('s', '')
            s = [int(a) for a in s.split()]
            ans = s[0]*1000
        else:
            print('Unknown Type')
        print(ans)
main()
