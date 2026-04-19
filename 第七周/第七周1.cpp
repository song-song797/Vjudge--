// Vjudge 第七周1

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> medicine;
int N, K;
bool check(int x) {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (medicine[i].first >= x) {
            ans += medicine[i].second;
        }
    }
    return ans <= K;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    medicine.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> medicine[i].first >> medicine[i].second;
    }
    int left = 1;
    int right = 1e9;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << left << '\n';
    return 0;
}
