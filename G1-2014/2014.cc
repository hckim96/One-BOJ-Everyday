#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> prime(K);
    for (auto& e: prime) {
        cin >> e;
        pq.push(e);
    }

    while (--N) {
        auto t = pq.top();
        pq.pop();

        for (auto e: prime) {
            if ((long long)t * e >= 1LL << 31) {
                break;
            }
            pq.push(t * e);

            if (t % e == 0) {
                break;
            }
        }
    }

    cout << pq.top() << '\n';
}