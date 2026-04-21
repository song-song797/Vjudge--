// Vjudge 第七周3

#include <bits/stdc++.h>
using namespace std;

int counts[300005];
vector<vector<int>> adj;
void dfs(int idx,int remain){
    for(auto v:adj[idx]){
        counts[v]=max(remain-1,counts[v]);
        dfs(v,counts[v]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;
 
    adj.resize(N+1);
    for(int i=2;i<=N;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    for(int i=1;i<=M;i++){
        int x,y;
        cin >> x >> y;
        if(counts[x]<y+1){
            counts[x]=y+1;
        }
    }
   
    dfs(1,counts[1]);
    
    int res=0;
    for(int i=1;i<=N;i++){
        if(counts[i]>0) res++;
    }
    cout << res << '\n';
    return 0;
}
