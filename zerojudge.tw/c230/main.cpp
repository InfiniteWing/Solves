#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct tree{
    int x, y, h, xy;
};

int compare (const void * a, const void * b)
{
    return (int)((*(tree*)a).xy - (*(tree*)b).xy);
}
int main()
{
    int n, x, y, h;
    while(scanf("%d",&n)!=EOF){
        tree trees[n];
        for(int i=0;i<n;i++){
            tree t;
            scanf("%d %d %d",&t.x,&t.y,&t.h);
            t.xy = t.x * t.y;
            trees[i] = t;
        }
        qsort (trees, n, sizeof(tree), compare);
        int _max = 0, _highest = trees[0].h;
        for(int i=1;i<n;i++){
            if(_highest - trees[i].h > _max)
                _max = _highest - trees[i].h;
            else if(trees[i].h > _highest)
                _highest = trees[i].h;
        }
        cout<<_max<<endl;
    }
    return 0;
}
