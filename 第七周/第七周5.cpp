// Vjudge 第七周5

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;
    string stk;
    string stk1;
    char last = '#';
    for (int i = 0; i < N; i++) {
        stk.push_back(S[i]);
        if (S[i] == ')' && !stk1.empty() && stk1[stk1.size() - 1] == '(') {
            while (!stk.empty() && stk[stk.size() - 1] != '(') {
                stk.pop_back();
            }
            stk.pop_back();
            stk1.pop_back();
        } else {
            if (S[i] == '(' || S[i] == ')') {
                stk1.push_back(S[i]);
            }
        }
    }
    cout << stk << '\n';
    return 0;
}
