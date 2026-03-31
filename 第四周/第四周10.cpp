// Vjudge 第四周 10
#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool visited[15][15];
vector<string> matrix;
int dfs(int x, int y, int step,int K,int H,int W) {
    int res = 0;
    if (step == K) {
        return 1;
    }
    visited[x][y] = true;
    for (int k = 0; k < 4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx<0||nx>=H||ny<0||ny>=W)
            continue;
        if(visited[nx][ny])
            continue;
        if(matrix[nx][ny]=='#')
            continue;
        res += dfs(nx, ny, step + 1, K, H, W);
    }
    visited[x][y] = false;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, K;
    cin >> H >> W >> K;
    matrix.resize(H);
    int ans = 0;
    for (int i = 0; i < H; i++) {
        cin >> matrix[i];
    }
    for (int i = 0; i < H;i++){
        for (int j = 0; j < W;j++){
            if(matrix[i][j]=='.')
                ans += dfs(i, j, 0, K, H, W);
        }
    }
    cout << ans << '\n';
    return 0;
}
