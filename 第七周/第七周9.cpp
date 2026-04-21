// Vjudge 第七周9

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,K,Q;
    cin >> N >> K >> Q;

    
    vector<int> A(N+1,0);
    set<pair<int, int>> VIP;
    set<pair<int, int>> Normal;
    for(int i=1;i<=K;i++){
        VIP.insert({0,i});
    }
    for(int i=K+1;i<=N;i++){
        Normal.insert({0,i});
    }
    long long sum = 0;
    while(Q--){
        int X,Y;
        cin >> X >> Y;
        int temp=A[X];
        A[X]=Y;
         if(N==K){
            sum=sum-temp+A[X];
            cout << sum << '\n';
            continue;
        }
        if (VIP.count({temp, X})){
            VIP.erase({temp,X});
            if (A[X] >= Normal.rbegin()->first){
                VIP.insert({A[X],X});
                sum=sum-temp+A[X];
            }else{
                int curr_y=Normal.rbegin()->first;
                int curr_x=Normal.rbegin()->second;
                Normal.erase(*Normal.rbegin());
                Normal.insert({A[X],X});
                VIP.insert({curr_y,curr_x});
                sum=sum-temp+curr_y;
            }
        }else{
            Normal.erase({temp,X});
            if (A[X] <= VIP.begin()->first){
                Normal.insert({A[X],X});
            }else{
                int curr_y=VIP.begin()->first;
                int curr_x=VIP.begin()->second;
                VIP.erase(VIP.begin());
                VIP.insert({A[X],X});
                Normal.insert({curr_y,curr_x});
                sum=sum-curr_y+A[X];
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
