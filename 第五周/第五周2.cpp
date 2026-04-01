// Vjudge 第五周 2

#include <bits/stdc++.h>
using namespace std;
int counts[5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        counts[a]++;
        counts[b]++;
        if (counts[a] > 2 || counts[b] > 2) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
}