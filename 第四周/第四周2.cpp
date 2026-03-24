// Vjudge 第四周 2
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int ans=0;
    int max_val=0;
    while(n--){
        int a;
        cin >> a;
        if(max_val>a){
            ans=max(max_val+a,ans);
        }else{
            max_val=a;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
