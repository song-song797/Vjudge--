// Vjudge 第四周 1
// TODO: 在这里补充题目描述和代码实现。

#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,x;
    cin >> n >> m >> x;
    vector<int> max_val(m,0);
    int ans=0;
    for (int i = 1; i <= n; i++){
        for(int j=0;j<m;j++){
            int val;
            cin >> val;
            if(val>max_val[j]){
                x=x-val+max_val[j];
                max_val[j]=val;
            }
        }
        if(x<0) break;
        ans++;
    }
    cout << ans << '\n';
}