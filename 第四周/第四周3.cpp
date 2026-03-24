// Vjudge 第四周 3
#include <bits/stdc++.h>
using namespace std;
long long C[105][105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i=1;i<=N-1;i++){
        for(int j=i+1;j<=N;j++){
            cin >> C[i][j];
        }
    }
    for(int i=1;i<=N-1;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=i+1;k<=j;k++){
                if(C[i][j]>C[i][k]+C[k][j]){
                    cout << "Yes" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
