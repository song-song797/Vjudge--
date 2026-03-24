// Vjudge 第四周 5
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> C(M + 1, 0);
    int sum = 0;
    for (int i = 1; i <= M; i++) {
        cin >> C[i];
        sum += C[i];
    }

    while(N--){
        int A, B;
        cin >> A >> B;
        C[A] = max(0, C[A] - B);
    }

    for (int i = 1; i <= M;i++){
        sum -= C[i];
    }
    cout << sum << '\n';
    return 0;
}
