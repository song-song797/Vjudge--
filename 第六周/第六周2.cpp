#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N + 1, 0);
    int gd;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        if (i == 1) {
            gd = a[i];
        } else {
            gd = gcd(gd, a[i]);
        }
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        int current = a[i]/gd;
        while(current%2==0||current%3==0){
            if(current%2==0){
                current = current / 2;
                res++;
            }
            if(current%3==0){
                current = current / 3;
                res++;
            } 
        }
        if(current!=1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << res << '\n';
    return 0;
}
