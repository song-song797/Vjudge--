// Vjudge 第五周 3
// TODO: 在这里补充题目描述和代码实现。

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> T(N + 1);
    int S = 0;
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
        S += T[i];
    }
    vector<int> dp(S / 2 + 1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = S / 2; j >= T[i]; j--) {
            dp[j] = max(dp[j], dp[j - T[i]] + T[i]);
        }
    }
    cout << S - dp[S / 2] << '\n';
}