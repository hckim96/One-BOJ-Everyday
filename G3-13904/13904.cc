#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // {w, d}
    vector<pair<int, int> > arr(N);
    int maxD = 0;
    for (auto & e: arr) {
        cin >> e.second >> e.first;
        maxD = max(maxD, e.second);
    }

    int answer = 0;
    vector<int> score(maxD + 1, 0);
    
    sort(arr.begin(), arr.end(), greater<pair<int, int> > ());

    for (auto e: arr) {
        int d = e.second;

        while (score[d]) {
            --d;
        }

        if (d) {
            score[d] = e.first;
            answer += score[d];
        }
    }

    cout << answer << '\n';
}
