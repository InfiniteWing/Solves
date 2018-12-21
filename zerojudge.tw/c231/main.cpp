#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int w, h=10000, b, ans;
bool isbomb(int *m,int x,int y){
    if(x < 0 || x >= w or y < 0 or y >= h)
    // out of range
        return false;
    return m[x+y*w] == 1;
}
void Explosion(int *m,int x,int y){
    if(x < 0 || x >= w or y < 0 or y >= h)
        // out of range
        return;
    if(m[x+y*w] == -1)
        // already checked
        return;
    else if(m[x+y*w] == 0){
        m[x+y*w] = -1;
        if(isbomb(m, x-1, y))
            Explosion(m, x-1, y);
        if(isbomb(m, x-1, y-1))
            Explosion(m, x-1, y-1);
        if(isbomb(m, x-1, y+1))
            Explosion(m, x-1, y+1);
        if(isbomb(m, x, y-1))
            Explosion(m, x, y-1);
        if(isbomb(m, x, y+1))
            Explosion(m, x, y+1);
        if(isbomb(m, x+1, y))
            Explosion(m, x+1, y);
        if(isbomb(m, x+1, y-1))
            Explosion(m, x+1, y-1);
        if(isbomb(m, x+1, y+1))
            Explosion(m, x+1, y+1);
        return;
    }
    else if(m[x+y*w] == 1){
        // has bomb
        m[x+y*w] = -1;
        // checked flag
        Explosion(m, x-1, y);
        Explosion(m, x-1, y-1);
        Explosion(m, x-1, y+1);
        Explosion(m, x, y-1);
        Explosion(m, x, y+1);
        Explosion(m, x+1, y);
        Explosion(m, x+1, y-1);
        Explosion(m, x+1, y+1);
        return;
    }
}

int main()
{
    while(scanf("%d %d %d",&w,&h,&b)!=EOF){
        ans = 0;
        int *m = (int *)malloc(w * h * sizeof(int));
        int x[b], y[b];
        for(int i=0; i<b; i++){
            scanf("%d %d", &x[i], &y[i]);
            x[i]--;
            y[i]--;
            m[x[i]+y[i]*w] = 1;
        }
        for(int i=0; i<b; i++){
            if(m[x[i]+y[i]*w] == 1){
                ans++;
                Explosion(m, x[i]-1,y[i]-1);
            }
        }
        cout<<ans<<endl;
    }
}
