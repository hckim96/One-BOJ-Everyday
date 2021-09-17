#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> prime(K);
    set<int> pushed;
    int pqMax = 0;
    for (auto& e: prime) {
        cin >> e;
        pq.push(e);
        pushed.insert(e);
        pqMax = max(pqMax, e);
    }

    while (--N) {
        auto t = pq.top();
        pq.pop();

        for (auto e: prime) {
            if ((long long)t * e >= 1LL << 31) {
                break;
            }
            if (pq.size() >= N && pqMax < t * e) {
                break;
            }
            if (pushed.count(t * e)) {
                continue;
            }
            pushed.insert(t * e);
            pq.push(t * e);
            pqMax = max(pqMax, t * e);
        }
    }

    cout << pq.top() << '\n';
}