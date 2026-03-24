// Vjudge 第四周 8
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Snake{
    int head_pos;
    int len;
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    deque<Snake> dq;
    int offset = 0;
    int tail_pos = 0;
    while (Q--) {
        int op;
        cin >> op;
        if(op==1){
            int l;
            cin >> l;
            Snake curr;
            curr.head_pos = tail_pos;
            curr.len = l;
            tail_pos += l;
            dq.push_back(curr);
        }
        if(op==2){
            Snake curr = dq.front();
            dq.pop_front();
            offset += curr.len;
        }
        if(op==3){
            int k;
            cin >> k;
            cout << dq[k - 1].head_pos-offset << '\n';
        }
    }
    return 0;
}
