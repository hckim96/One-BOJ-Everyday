#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > arr(N);

    for (auto &[f, s]: arr) {
        cin >> f >> s;
    }

    sort(arr.begin(), arr.end(), cmp);

    for (auto &[f, s]: arr) {
        cout << f << ' ' << s << '\n';
    }
}