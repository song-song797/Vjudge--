// Vjudge 第四周 7
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int max_A = -1e9;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        max_A = max(max_A, A);
    }
    int max_B = -1e9;
    for (int i = 0; i < N;i++){
        int B;
        cin >> B;
        max_B = max(max_B, B);
    }
    cout << max_A + max_B << '\n';
    return 0;
}
