// Vjudge 第七周7

#include <bits/stdc++.h>
using namespace std;
int counts[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<pair<int, int>> res(N + 1);
    int j = 1;
    for (int i = 0; i < 3 * N; i++) {
        int A;
        cin >> A;
        counts[A]++;
        if (counts[A] == 2) {
            res[j].first = i + 1;
            res[j].second = A;
            j++;
        }
    }
    sort(res.begin() + 1, res.end());
    for (int i = 1; i <= N; i++) {
        cout << res[i].second << ' ';
    }
    return 0;
}
