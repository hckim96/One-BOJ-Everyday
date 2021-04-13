#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > jewelry;
    priority_queue<int> canSteal;
    vector<int> bag(K);

    for (int i = 0; i < N; ++i) {
        int m, v;
        cin >> m >> v;

        jewelry.push({m, v});
    }

    for (auto & e: bag) {
        cin >> e;
    }

    sort(bag.begin(), bag.end());
    
    long long answer = 0;
    for (auto b: bag) {
        while (!jewelry.empty() && jewelry.top().first <= b) {
            canSteal.push(jewelry.top().second);
            jewelry.pop();
        }

        if (!canSteal.empty()) {
            answer += canSteal.top();
            canSteal.pop();
        }
    }

    cout << answer << '\n';
}
