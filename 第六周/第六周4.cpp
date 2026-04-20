#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N;i++){
        A.push_back(A[i] + M);
    }
    int current_sum = A[0],max_sum = A[0];
    int curr_len = 1;
    for (int i = 1; i < 2 * N; i++) {
        current_sum += A[i]%M;
        if(A[i-1]==A[i]||A[i]-A[i-1]==1){
            curr_len++;
        } else {
            current_sum = A[i]%M;
            curr_len = 1;
        }
        if (curr_len == N) {
            max_sum = sum;  
            break;
        }
        max_sum = max(current_sum, max_sum);
    }
    cout << sum - max_sum << '\n';
    return 0;
}
