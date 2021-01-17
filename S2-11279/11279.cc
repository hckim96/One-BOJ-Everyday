#include <iostream>
#include <queue>

using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> q;

    cin >> N;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (q.empty()) {
                cout << "0\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else {
            q.push(x);
        }
    }
}