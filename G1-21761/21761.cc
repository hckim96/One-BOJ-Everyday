#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<long long> v(4, 0);
    for (auto& e: v) {
        cin >> e;
    }

    vector<priority_queue<int> > pq(4);
    for (int i = 0; i < N; ++i) {
        char c;
        int num;
        cin >> c >> num;
        pq[c - 'A'].push(num);
    }

    for (int i = 0; i < K; ++i) {
        int idx = 0;
        double ttmp = -1e18;
        for (int j = 0; j < 4; ++j) {
            if (pq[j].empty()) continue;
            double tmp = (double)pq[j].top() / v[j];
            if (tmp > ttmp) {
                ttmp = tmp;
                idx = j;
            }
        }
        v[idx] += pq[idx].top();
        cout << char('A' + idx) << ' ' << pq[idx].top() << '\n';
        pq[idx].pop();
    }
}