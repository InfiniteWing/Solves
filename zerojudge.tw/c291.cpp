#include <iostream>

using namespace std;

int Map[50001];
int Check[50001];

int ans = 0;
void Compute(int n){
    if(Check[n] == 1){
        ans++;
        return;
    }
    Check[n] = 1;
    Compute(Map[n]);
}

int main()
{
    int n;
    while(cin>>n){
        ans = 0;
        for(int i=0;i<n;i++){
            cin>>Map[i];
            Check[i]=0;
        }
        for(int i=0;i<n;i++){
            if(Check[i] == 1){
                continue;
            }
            Compute(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
