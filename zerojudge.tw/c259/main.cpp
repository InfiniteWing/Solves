#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#
#   Binary Indexed Tree, http://www.csie.ntnu.edu.tw/~u91029/Sequence.html
#

using namespace std;

unsigned long long int arr[300001];
unsigned long long int t[300001];
int N;
// е硉―程bit硂琌ㄤい贺よΑ
int lower_bit(int n)
{
    return n & -n;
}

// value[1] + value[2] + ... + value[n]
unsigned long long int sum(int n)
{
    unsigned long long int s = 0;
    while (n > 0)
    {
        s += t[n];
        n -= lower_bit(n);
    }
    return s;
}

// value[n] += d
void add(int n, long int d)
{
    while (n <= N)
    {
        t[n] += d;
        n += lower_bit(n);
    }
}

// value[a] + value[a+1] + ... + value[b]
unsigned long long int query(int a, int b)
{
    if (a > b) swap(a, b);
    return sum(b) - sum(a-1);
}

int init(int n){
    for(int x=1;x<=n;++x){
        t[x]=arr[x];
        int y=x-lower_bit(x);
        for(int i=x-1;i>y;i-=lower_bit(i)){
            t[x] +=t[i];
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,l,r,t;
    long int v;
    while(cin>>n>>m){
        N=n+1;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        init(n);
        for(int i=0;i<m;i++){
            cin>>t>>l>>r;
            if(t==1){
                cin>>v;
                for(int j=l;j<=r;j++){
                    if(arr[j]<v){
                        add(j,v-arr[j]);
                        arr[j]=v;
                    }
                }
            }else{
                cout<<query(l,r)<<endl;
            }
        }
    }
    return 0;
}
/*

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;
long int arr[300001];    // 计
unsigned long long int sum[300001*4+3], T;

void build(int N)
{
    int i;
    for (T=1; T<N+2; T<<=1) ;
    sum[T] = 0;
    for (i=0; i<N; ++i) sum[T+1+i] = arr[i];
    for (++i; i<T; ++i) sum[T+i] = 0;
    for (i=T-1; i; --i) sum[i] = sum[2*i] + sum[2*i+1];
}

// 穝絛瞅[i,i]穝计n
void update(int i, int n)
{
    sum[i += T] = n;
    for (; i^1; i>>=1)
        sum[i>>1] = sum[i] + sum[i^1];
}

// 琩高絛瞅[i,j]仓璸羆㎝
unsigned long long int query(int i, int j)
{
    unsigned long long int n = 0;
    for (i+=T-1, j+=T+1; i^j^1; i>>=1, j>>=1)
    {
        if (~i & 1) n += sum[i^1];
        if (j & 1) n += sum[j^1];
    }
    return n;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,l,r,t;
    long int v;
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        build(n);
        for(int i=0;i<m;i++){
            cin>>t>>l>>r;
            if(t==1){
                cin>>v;
                for(int j=l-1;j<r;j++){
                    if(arr[j]<v){
                        update(j+1,v);
                        arr[j]=v;
                    }
                }
            }else{
                cout<<query(l,r)<<endl;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;


unsigned long long int GetSum(long int *datas,int l, int r){
    unsigned long long int sum=0;
    for(int i=l-1;i<r;i++){
        sum+=datas[i];
    }
    return sum;
}

void SetMax(long int *datas,int l, int r,long int v){
    for(int i=l-1;i<r;i++){
        datas[i]=datas[i]>v?datas[i]:v;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,l,r,t;
    long int v;
    long int datas[300001];
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>datas[i];
        }
        for(int i=0;i<m;i++){
            cin>>t>>l>>r;
            if(t==1){
                cin>>v;
                SetMax(datas,l,r,v);
            }else{
                cout<<GetSum(datas,l,r)<<endl;
            }
        }
    }
    return 0;
}
*/
