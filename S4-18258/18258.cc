#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    queue<int> q;

    while (N--) {
        string s;
        cin >> s;

        if (s == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if (s == "pop") {
            if (q.size()) {
                cout << q.front() << '\n';
                q.pop();
            } else {
                cout << "-1\n";                
            }
        } else if (s == "front") {
            if (q.size()) {
                cout << q.front() << '\n';
            } else {
                cout << "-1\n";
            }
        } else if (s == "back") {
            if (q.size()) {
                cout << q.back() << '\n';
            } else {
                cout << "-1\n";
            }
        } else if (s == "size") {
            cout << q.size() << '\n';
        } else {
            cout << q.empty() << '\n';
        }
    }
}