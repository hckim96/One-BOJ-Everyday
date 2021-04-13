#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second > p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    multiset<int> bag;
    vector<pair<int, int> > jewelry(N);
    for (auto & e: jewelry) {
        cin >> e.first >> e.second;
    }
    
    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;
        bag.insert(num);
    }

    sort(jewelry.begin(), jewelry.end(), cmp);
    
    long long answer = 0;

    for (auto j: jewelry) {
        if (bag.empty()) {
            break;
        }

        auto it = bag.lower_bound(j.first);
        if (it != bag.end()) {
            bag.erase(it);
            answer += j.second;
        }
    }

    cout << answer << '\n';
}
