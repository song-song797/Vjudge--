// Vjudge 第四周 4
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int R;
            cin >> R;
            cout << R * W << '\n';
            H -= R;
        }
        if (op == 2) {
            int C;
            cin >> C;
            cout << H * C << '\n';
            W -= C;
        }
    }
    return 0;
}
