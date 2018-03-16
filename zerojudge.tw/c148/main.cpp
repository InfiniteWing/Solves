#include <iostream>
#include <stdio.h>
using namespace std;

int maps[1003][103];
int records[1003][103];
int ans[1003][103];
int best=9999999;
int n,m;
int b,e;
int k,xi,yi;

//direction: 1:left 2:top 3:right 4:down
void DFS(int step, int direction, int x, int y){
    if(step>=best){
        return;
    }
    if(x==n&&y==e+1){
        if(step<best){
            best=step;
        }
        return;
    }
    if(records[x][y]==1){
        return;
    }
    if(step<=ans[x][y]){
        ans[x][y] = step;
    }else{
        return;
    }
    records[x][y]=1;
    if(direction==3){
        if(maps[x][y+1]!=1){
            DFS(step,3,x,y+1);
        }
        if(maps[x+1][y]!=1){//down
            DFS(step+1,4,x+1,y);
        }
        if(maps[x-1][y]!=1){//top
            DFS(step+1,2,x-1,y);
        }
    }else if(direction==4){
        if(maps[x+1][y]!=1){
            DFS(step,4,x+1,y);
        }
        if(maps[x][y+1]!=1){//right
            DFS(step+1,3,x,y+1);
        }
        if(maps[x][y-1]!=1){//left
            DFS(step+1,1,x,y-1);
        }
    }else if(direction==1){
        if(maps[x][y-1]!=1){
            DFS(step,1,x,y-1);
        }
        if(maps[x+1][y]!=1){//down
            DFS(step+1,4,x+1,y);
        }
        if(maps[x-1][y]!=1){//top
            DFS(step+1,2,x-1,y);
        }
    }else if(direction==2){
        if(maps[x-1][y]!=1){
            DFS(step,2,x-1,y);
        }
        if(maps[x][y+1]!=1){//right
            DFS(step+1,3,x,y+1);
        }
        if(maps[x][y-1]!=1){//left
            DFS(step+1,1,x,y-1);
        }
    }
    records[x][y]=0;
}

int main()
{
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&m);
        scanf("%d",&b);
        scanf("%d",&e);
        for(int i=1;i<=n;i++){
            for(int j =1;j<=m;j++){
                maps[i][j] = 0;
                records[i][j] = 0;
                ans[i][j] = 99999;
            }
        }
        for(int i=0;i<=n+1;i++){
            maps[i][0]=1;//障礙物
            maps[i][m+1]=1;//障礙物
        }
        for(int j =0;j<=m+1;j++){
            maps[0][j]=1;//障礙物
            maps[n+1][j]=1;//障礙物
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d %d",&xi,&yi);
            maps[xi+1][yi+1]=1;//障礙物
        }
        /*
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                if(i==1&&j==b+1){
                    cout<<"Ｓ";
                }
                else if(i==m&&j==e+1){
                    cout<<"Ｅ";
                }
                else if(maps[i][j]!=1){
                    cout<<"　";
                }
                else{
                    cout<<"口";
                }
            }
            cout<<endl;
        }
        */
        best = 999999;
        DFS(0,4,1,b+1);
        printf("%d\n",best);
    }
}
