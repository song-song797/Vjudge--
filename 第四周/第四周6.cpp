// Vjudge 第四周 6
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int count = 0;
    vector<unordered_set<int>> adj(N + 1);

    while(M--){
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if(u==v){
            count++;
            continue;
        }
        if(adj[u].count(v)){
            count++;
            continue;
        }
        adj[u].insert(v);
    }

    cout << count << '\n';
    return 0;
}
