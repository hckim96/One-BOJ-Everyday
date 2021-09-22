#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    deque<int> dq;

    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    cout << "<";
    while (!dq.empty()) {
        int cnt = K - 1;
        while (cnt--) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cout << dq.front();
        dq.pop_front();
        if (!dq.empty()) {
            cout << ", ";
        }
    }
    cout << ">\n";
}