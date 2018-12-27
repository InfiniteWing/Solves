#include <iostream>
#include <string>
using namespace std;
int cards[6] = {0};
int isend(int now){
    for(int i =0;i<6;i++){
        if(cards[i] == 0)
            continue;
        return now+i+1 > 31;
    }
}
int cantkill(int now){
    int pick = 0;
    for(int i =0;i<6;i++){
        if(cards[i] == 0)
            continue;
        if(now+i+1 > 31)
            break;
        cards[i] -= 1;
        if(isend(now+i+1)){
            cards[i] += 1;
            pick = 1;
            break;
        }
        else
            cards[i] += 1;
    }
    return pick;
}
int main()
{
    string s;
    while(cin>>s){
        for(int i =0;i<6;i++){
            cards[i] = 4;
        }
        int pts = 0, pi = s.size(), pick = 0;
        for(int i =0;i<s.size();i++){
            int p = s[i]-'0';
            cards[p-1]--;
            pts += p;
        }
        while(1){
            if(isend(pts) == 1)
                break;
            pick = 0;
            for(int i =0;i<6;i++){
                if(cards[i] == 0)
                    continue;
                if(pts+i+1>31)
                    break;
                cards[i]--;
                if(isend(pts+i+1) == 1){
                    pts += i+1;
                    pick = 1;
                    break;
                }
                else
                    cards[i] += 1;
            }
            if(pick == 0){
                for(int i =0;i<6;i++){
                    if(pts+i+1>31)
                        break;
                    if(cards[i] > 0){
                        cards[i] -= 1;
                        if(cantkill(pts+i+1) == 0){
                            pts += i+1;
                            pick = 1;
                            break;
                        }
                        else
                            cards[i] += 1;
                    }
                }
                if(pick == 0){
                    for(int i =5;i>=0;i--){
                        if(cards[i] > 0){
                            cards[i] -= 1;
                            pts += i+1;
                            break;
                        }
                    }
                }
            }
            pi++;
        }
        if(pi%2 == 0)
            cout<<s<<" B"<<endl;
        else
            cout<<s<<" A"<<endl;
    }
    return 0;
}
