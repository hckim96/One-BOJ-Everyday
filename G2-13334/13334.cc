#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > arr(N);

    for (auto & e: arr) {
        cin >> e.first >> e.second;
        if (e.first > e.second) {
            swap(e.first, e.second);
        }
    }

    int D;
    cin >> D;

    sort(arr.begin(), arr.end(), cmp);
    priority_queue<int, vector<int>, greater<int> > pq;

    int answer = 0;
    for (auto & e: arr) {
        if (e.second - e.first > D) {
            continue;
        }
        
        pq.push(e.first);
        while (pq.top() < e.second - D) {
            pq.pop();
        }

        answer = max(answer, (int)pq.size());
    }

    cout << answer << '\n';
}
