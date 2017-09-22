en="abcdefgh"
en_hash={}
for i,c in enumerate(en):
    en_hash[c]=i+1

    
map=[]
for i in range(9):
    map.append([])
    for j in range(9):
        map[i].append(0)
    

def Init():
    for i in range(9):
        for j in range(9):
            map[i][j]=0
def BFS(sx,sy,step):
    Set(sx-2,sy+1,step)
    Set(sx-1,sy+2,step)
    Set(sx+1,sy+2,step)
    Set(sx+2,sy+1,step)
    
    Set(sx+2,sy-1,step)
    Set(sx+1,sy-2,step)
    Set(sx-1,sy-2,step)
    Set(sx-2,sy-1,step)
    
def Set(tx,ty,step):
    if(tx<1 or ty<1 or tx>8 or ty>8):
        return
    if(map[tx][ty]!=0):
        return
    map[tx][ty]=step


        
while True:
    try:
        s=input()
    except EOFError:
        break
    d=s.split(' ')
    start_x=en_hash[d[0][0]]
    start_y=int(d[0][1])
    
    end_x=en_hash[d[1][0]]
    end_y=int(d[1][1])
    Init()
    if(start_x==end_x and start_y==end_y):
        print("To get from {} to {} takes 0 knight moves.".format(d[0],d[1]))
    else:
        step=1
        BFS(start_x,start_y,step)
        while(True):
            if(map[end_x][end_y]!=0):
                break
            for i in range(1,9):
                for j in range(1,9):
                    if(map[i][j]==step):
                        BFS(i,j,step+1)
            step+=1
                        
        print("To get from {} to {} takes {} knight moves.".format(d[0],d[1],map[end_x][end_y]))
        
    
    