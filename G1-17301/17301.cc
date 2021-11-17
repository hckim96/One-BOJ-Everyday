#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // np0 np1 ... npn
    auto f = [](int n) {
        if (n == 0) return 1LL;

        long long ret = 1;
        long long tmp = 1;

        for (int i = n; i >= 1; --i) {
            tmp *= i;
            tmp %= MOD;
            ret += tmp;
            ret %= MOD;
        }
        return ret;
    };

    int N;
    cin >> N;
    
    long long all = f(N) - 1LL;
    int n, cn, c;
    n = cn = c = 0;

    while (N--) {
        string s;
        cin >> s;

        bool hasN = false;
        bool hasC = false;
        bool hasCN = false;
        bool hasNC = false;

        for (auto e: s) {
            if (e == 'N') {
                hasN = true;
                if (hasC) hasCN = true;
            } else if (e == 'C') {
                hasC = true;
                if (hasN) hasNC = true;
            }
        }

        if (hasNC) continue;

        if (hasCN) {
            ++cn;
        } else if (hasN) {
            ++n;
        } else {
            ++c;
        }
    }    

    long long noNC = (f(c) * f(n) % MOD * (cn + 1) % MOD - 1) % MOD;
    long long answer = all - noNC;
    answer %= MOD;
    if (answer < 0) answer += MOD;

    cout << answer << '\n'; 
}