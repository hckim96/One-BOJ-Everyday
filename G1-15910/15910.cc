#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

map<pair<int, char>, int> nextState {
    {{0, 'B'}, 1},
    {{1, 'B'}, 1},
    {{1, 'A'}, 2},
    {{2, 'N'}, 3},
    {{3, 'A'}, 4},
    {{4, 'N'}, 5},
    {{5, 'A'}, 6},
    {{6, 'N'}, 5},
    {{6, 'B'}, 1},
};

vector<vector<char> > avail {
    {'B'},
    {'B', 'A'},
    {'N'},
    {'A'},
    {'N'},
    {'A'},
    {'N', 'B'},
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;

    int state = 0;

    vector<vector<int> > dp(7, vector<int> (s.size(), -1));

    function<int(int, int)> f =[&](int state, int idx) {
        if (idx >= s.size()) {
            if (state == 6) {
                return 0;
            } else {
                return (int)1e9;
            }
        }

        int& ret = dp[state][idx];
        if (ret != -1) return ret;

        ret = 1e9;
        for (auto e: avail[state]) {
            ret = min(ret, f(nextState[{state, e}], idx + 1) + (e != s[idx]));
        }

        return ret;
    };

    cout << f(0, 0) << '\n';

}