// Vjudge 第七周8

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> menu(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> menu[i].first >> menu[i].second;
    }
    return 0;
}
