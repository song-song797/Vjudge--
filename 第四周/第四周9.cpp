// Vjudge 第四周 9
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (int i = 0; i < s.size()-1;i++){
        if(s[i]=='W'&&s[i+1]=='A'){
            s[i] = 'A';
            s[i + 1] = 'C';
            if(i>=1)
                i-=2;
        }
    }
    cout << s << '\n';
    return 0;
}
