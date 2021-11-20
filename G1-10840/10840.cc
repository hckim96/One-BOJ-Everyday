#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int> > p1(s1.size(), vector<int> (26, 0));
    vector<vector<int> > p2(s2.size(), vector<int> (26, 0));
    
    for (int i = 0; i < s1.size(); ++i) {
        ++p1[i][s1[i] - 'a'];
        if (i) {
            for (int j = 0; j < 26; ++j) {
                p1[i][j] += p1[i - 1][j];
            }
        }
    }
    for (int i = 0; i < s2.size(); ++i) {
        ++p2[i][s2[i] - 'a'];
        if (i) {
            for (int j = 0; j < 26; ++j) {
                p2[i][j] += p2[i - 1][j];
            }
        }
    }

    auto check = [&](int len) {
        if (len == 0) return true;
        if (len > s1.size() && len > s2.size()) return false;
        set<vector<int> > s;

        for (int i = 0; i + len - 1 < s1.size(); ++i) {
            vector<int> tmp(26, 0);
            for (int j = 0; j < 26; ++j) {
                tmp[j] += p1[i + len - 1][j];
                if (i) tmp[j] -= p1[i - 1][j];
            }
            s.insert(tmp);
        }

        for (int i = 0; i + len - 1 < s2.size(); ++i) {
            vector<int> tmp(26, 0);
            for (int j = 0; j < 26; ++j) {
                tmp[j] += p2[i + len - 1][j];
                if (i) tmp[j] -= p2[i - 1][j];
            }
            if (s.count(tmp)) return true;
        }
        return false;
    };

    for (int i = min(s1.size(), s2.size()); i >= 0; --i) {
        if (check(i)) {
            cout << i << '\n';
            return 0;
        }
    }
}