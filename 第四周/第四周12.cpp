#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    int count = 0;
    do {
        bool valid = true;
        for (int i = 0; i <= N - K; i++) {
            int L = i;
            int R = i + K - 1;
            bool is_Pal = true;
            while (L < R) {
                if (S[L] != S[R]) {
                    is_Pal = false;
                    break;
                }
                L++;
                R--;
            }
            if (is_Pal){
                valid = false;
                break;
            }
        }
        if (valid) {
            count++;
        }
    } while (next_permutation(S.begin(), S.end()));
    cout << count << '\n';
}