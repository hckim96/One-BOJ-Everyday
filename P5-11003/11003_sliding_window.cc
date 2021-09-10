#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    // value, idx
    deque<pair<int, int> > dq;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        while (!dq.empty() && dq.back().first >= num) {
            dq.pop_back();
        }
        while (!dq.empty() && dq.front().second < i - L + 1) {
            dq.pop_front();
        }
        dq.push_back({num, i});
        cout << dq.front().first << ' ';
    }
    cout << '\n';
}