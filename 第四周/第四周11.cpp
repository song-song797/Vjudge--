// Vjudge 第四周 11
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N + 1, 0);
    for (int i = 1; i <= N;i++){
        cin >> X[i];
    }
    vector<int> P(N + 1, 0);
    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N;i++){
        cin >> P[i];
        prefix[i] = P[i] + prefix[i - 1];
    }

    int Q;
    cin >> Q;
    while(Q--){
        int L, R;
        cin >> L >> R;
        int left = lower_bound(X.begin() + 1, X.end(), L) - X.begin();
        int right = upper_bound(X.begin() + 1, X.end(), R) - X.begin();
        int ans = prefix[right - 1] - prefix[left - 1];
        cout << ans << '\n';
    }
    return 0;
}
