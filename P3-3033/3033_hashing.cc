#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int L;
    cin >> L;
    string s;
    cin >> s;

    long long MOD = 1e5 + 3;
    long long MUL = 2;

    auto check = [&](int l) {
        vector<vector<int> > hashTable(MOD);
        long long h = 0;
        long long MUL_POW_L = 1;
        for (int i = 0; i < l; ++i) {
            h *= MUL;
            h += s[i] - 'a' + 1;
            h %= MOD;
            MUL_POW_L *= MUL;
            MUL_POW_L %= MOD;
        }
        hashTable[h].push_back(0);

        for (int i = 1; i + l - 1 < L; ++i) {
            h *= MUL;
            h %= MOD;
            h -= (1LL * (s[i - 1] - 'a' + 1) * MUL_POW_L) % MOD;
            h += s[i + l - 1] - 'a' + 1; 
            h %= MOD;
            if (h < 0) h += MOD;

            for (auto idx: hashTable[h]) {
                if (s.compare(i, l, s, idx, l) == 0) return true;
            }
            hashTable[h].push_back(i);
        }
        return false;
    };

    int lo = 0;
    int hi = L;

    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n';
}