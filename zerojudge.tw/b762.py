def main():
    n = int(input())
    combo = 0
    k, a, d = 0, 0, 0
    for _ in range(n):
        s = input().strip()
        if(s == 'Get_Kill'):
            combo += 1
            k += 1
            if(combo < 3):
                print('You have slain an enemie.')
            elif(combo < 4):
                print('KILLING SPREE!')
            elif(combo < 5):
                print('RAMPAGE~')
            elif(combo < 6):
                print('UNSTOPPABLE!')
            elif(combo < 7):
                print('DOMINATING!')
            elif(combo < 8):
                print('GUALIKE!')
            else:
                print('LEGENDARY!')
        if(s == 'Get_Assist'):
            a += 1
        if(s == 'Die'):
            d += 1
            if(combo < 3):
                print('You have been slained.')
            else:
                print('SHUTDOWN.')
            combo = 0
    print('{}/{}/{}'.format(k,d,a))
                
main()