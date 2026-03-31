// Vjudge 第四周 16
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());

    vector<pair<int, int>> ans;
    int curr_L = A[0].first;
    int curr_R = A[0].second;
    for (int i = 1; i < N; i++) {
        if(A[i].first<=curr_R){
            curr_R = max(curr_R, A[i].second);
        }else{
            ans.push_back({curr_L, curr_R});
            curr_L = A[i].first;
            curr_R = A[i].second;
        }
    }
    ans.push_back({curr_L, curr_R});
    for (int i = 0; i < ans.size();i++){
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
        return 0;
}
