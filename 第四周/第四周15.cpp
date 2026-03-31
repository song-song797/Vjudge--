// Vjudge 第四周 15
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dist;
int bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int max_len = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] != -1) {
                continue;
            } else {
                dist[v] = dist[u] + 1;
                max_len = max(max_len, dist[v]);
                q.push(v);
            }
        }
    }
    return max_len;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N1, N2, M;
    cin >> N1 >> N2 >> M;

    adj.resize(N1 + N2 + 1);
    dist.assign(N1 + N2 + 1, -1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << bfs(1) + bfs(N1 + N2) + 1 << '\n';
}
