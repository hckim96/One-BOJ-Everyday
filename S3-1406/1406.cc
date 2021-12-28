#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int cur = 0;
    string s;
    stack<char> st;
    stack<char> st2;
    cin >> s;
    for (auto e: s) {
        st.push(e);
    }

    string tmp = "";
    int N;
    cin >> N;
    while (N--) {
        char op1, op2;
        cin >> op1;
        if (op1 == 'L') {
            if (st.size()) {
                st2.push(st.top());
                st.pop();
            }
        } else if (op1 == 'D') {
            if (st2.size()) {
                st.push(st2.top());
                st2.pop();
            }
        } else if (op1 == 'B') {
            if (st.size()) st.pop();
        } else {
            cin >> op2;
            st.push(op2);
        }
    }

    while (st.size()) {
        tmp += st.top();
        st.pop();
    }
    reverse(all(tmp));
    while (st2.size()) {
        tmp += st2.top();
        st2.pop();
    }
    cout << tmp << '\n';
}