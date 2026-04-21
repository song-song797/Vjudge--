// Vjudge 第七周6

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N + 1, vector<int>(2, 0));
    dp[1][0] = M;
    for (int i = 2; i <= N - 1; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = ((dp[i - 1][0] * (M - 1)) % MOD + (dp[i - 1][1] * (M - 2)) % MOD) % MOD;
    }
    dp[N][1] = ((dp[N - 1][0] * (M - 1)) % MOD + (dp[N - 1][1] * (M - 2)) % MOD) % MOD;
    cout << dp[N][1] << '\n';
    return 0;
}
