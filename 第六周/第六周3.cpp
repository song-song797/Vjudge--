#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> adj;
int max_floor = 1;
unordered_set<int> visited;

void dfs(int idx) {
    visited.insert(idx);
    for(auto v:adj[idx]){
        if(visited.count(v))
            continue;
        max_floor = max(max_floor, v);
        dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N;i++){
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    dfs(1);
    cout << max_floor << '\n';
    return 0;
}
