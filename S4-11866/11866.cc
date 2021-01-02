#include <iostream>
#include <queue>

using namespace std;

int N, K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        q.push(i);    
    }

    int cnt = 0;

    cout << "<";
    while (!q.empty()) {
        if (cnt == K - 1) {
            cout << q.front();
            q.pop();
            if (q.empty()) {
                cout << ">\n";
            } else {
                cout << ", ";
            }
        } else {
            q.push(q.front());
            q.pop();
        }
        cnt = (cnt + 1) % K;
    }
}