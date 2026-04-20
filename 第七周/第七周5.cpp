// Vjudge 第七周5

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;
    stack<char> stk;
    stack<char> stk1;
    char last = '#';
    for (int i = 0; i < N; i++) {
        stk.push(S[i]);
        if (S[i] == ')' && stk1.top() == '(') {
            while (!stk.empty() && stk.top() != '(') {
                stk.pop();
            }
            stk.pop();
            stk1.pop();
            
        }
        if (S[i] == '(' || S[i] == ')') {
            stk1.push(S[i]);
        }
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}
