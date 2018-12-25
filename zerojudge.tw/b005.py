def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        arrs = []
        row_dif = []
        col_dif = []
        for _ in range(n):
            arr = input().split()
            arr = [int(a) for a in arr]
            arrs.append(arr)
        for i in range(n):
            s_row = 0
            s_col = 0
            for j in range(n):
                s_row += arrs[i][j]
                s_col += arrs[j][i]
            if(s_row%2!=0):
                row_dif.append(i+1)
            if(s_col%2!=0):
                col_dif.append(i+1)
        if(len(row_dif) == 0 and len(col_dif) == 0):
            print('OK')
        elif(len(row_dif) == 1 and len(col_dif) == 1):
            print('Change bit ({},{})'.format(row_dif[0],col_dif[0]))
        else:
            print('Corrupt')
            
        
main()