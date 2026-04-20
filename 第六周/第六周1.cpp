#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    while (prev_permutation(P.begin(), P.end())) {
        for (int i = 0; i < N; i++) {
            cout << P[i] << ' ';
        }
        break;
    }
    return 0;
}
