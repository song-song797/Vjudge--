// Vjudge 第七周2

#include <bits/stdc++.h>
using namespace std;
int N, T, M;
int res = 0;
vector<int> teams;
vector<int> conflicts;
int empty_T;
void dfs(int idx) {
    if (empty_T > N - idx + 1)
        return;
    if (idx == N + 1 && empty_T == 0) {
        res++;
        return;
    }

    for (int i = 1; i <= T; i++) {
        bool valid = false;
        if ((teams[i] & conflicts[idx]) != 0)
            continue;
        if (teams[i] == 0) {
            valid = true;
            empty_T--;
        }
        teams[i] = teams[i] | (1 << idx);
        dfs(idx + 1);
        teams[i] = teams[i] ^ (1 << idx);
        if (teams[i] == 0)
            empty_T++;
        if (valid) {
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T >> M;
    teams.assign(T + 1, 0);
    conflicts.assign(N + 1, 0);
    empty_T = T;
    for (int i = 1; i <= M; i++) {
        int A, B;
        cin >> A >> B;
        conflicts[A] = conflicts[A] | (1 << B);
        conflicts[B] = conflicts[B] | (1 << A);
    }
    dfs(1);
    cout << res << '\n';
    return 0;
}
