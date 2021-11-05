#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<int> cnt(N + 1, 0);
    vector<set<int> > down(N + 1);

    for (int i = 0; i < M; ++i) {
        int X, Y;
        cin >> X >> Y;
        down[X].insert(Y);
        ++cnt[X];
    }
    
    deque<int> dq;

    for (int i = N; i >= 1; --i) {
        for (int j = 0; j < cnt[i]; ++j) {
            if (down[i].count(dq[j]) == 0) {
                cout << "-1\n";
                return 0;
            }
        }
        if (cnt[i] == dq.size()) dq.push_back(i);
        else dq.insert(dq.begin() + cnt[i], i);
    }

    vector<int> val(N + 1, 0);
    for (int i = 0; i < dq.size(); ++i) val[dq[i]] = i + 1;
    for (int i = 1; i <= N; ++i) cout << val[i] << ' ';
}