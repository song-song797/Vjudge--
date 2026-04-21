// Vjudge 第七周8

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> menu(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> menu[i].first >> menu[i].second;
    }

    vector<vector<int>> dp(N + 1, vector<int>(2, -1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        dp[i][1] = max(dp[i][1], dp[i - 1][1]);
        if (menu[i].first == 0) {
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + menu[i].second);
            dp[i][0] = max(dp[i][0], dp[i - 1][0] + menu[i].second);
        } else {
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + menu[i].second);
        }
    }

    cout << max(dp[N][0], dp[N][1]) << '\n';
    return 0;
}
