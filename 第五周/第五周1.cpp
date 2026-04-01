// Vjudge 第五周 1
// TODO: 在这里补充题目描述和代码实现。

#include <bits/stdc++.h>
using namespace std;

int counts[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        counts[a]++;
        counts[b]++;
        if (i == N - 2 && (counts[a] == N - 1 || counts[b] == N - 1)) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}
