#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        int index = 0;
        char s;
        s = getchar();
        for(int i=0;i<n*n;i++){
            s = getchar();
            if(i == index){
                cout<<s;
                index += n+1;
            }
        }
        cout<<endl;
    }
    return 0;
}
