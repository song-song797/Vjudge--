// Vjudge 第四周 14
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            string temp = s;
            temp[i] = '1';
            for (int j = 0; j < s.size(); j++) {
                if (temp[j] == '?') {
                    temp[j] = '0';
                }
            }
            if (stoll(temp, nullptr, 2) <= n) {
                s[i] = '1';
            }else{
                s[i] = '0';
            }
        }
    }
    if (stoll(s, nullptr, 2) > n) {
        cout << -1 << '\n';
    } else {
        cout << stoll(s, nullptr, 2) << '\n';
    }
    return 0;
}
