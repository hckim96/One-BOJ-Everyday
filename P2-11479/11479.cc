#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;

    auto buildSA = [&](string& s) {
        int N = s.size();
        vector<int> sa(N), r(2 * N, 0), nr(2 * N, 0);
        for (int i = 0; i < N; ++i) {
            sa[i] = i;
            r[i] = s[i];
        }
        for (int d = 1; d < N; d <<= 1) {
            auto cmp = [&](int i, int j) {
                return r[i] < r[j] || (r[i] == r[j] && r[i + d] < r[j + d]);
            };
            sort(all(sa), cmp);
            nr[sa[0]] = 1;
            for (int i = 1; i < N; ++i) {
                nr[sa[i]] = nr[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            }
            r = nr;
        }
        return sa;
    };

    auto buildLCP = [&](string& s) {
        int N = s.size();
        auto sa = buildSA(s);
        vector<int> lcp(N, 0), isa(N);
        for (int i = 0; i < N; ++i) {
            isa[sa[i]] = i;
        }
        for(int k = 0, i = 0;i < N;++i) {
            if(isa[i]){
                for(int j = sa[isa[i]-1]; max(i, j) + k < N && s[i+k] == s[j+k]; ++k);
                lcp[isa[i]] = (k ? k-- : 0);
            }
        }
        return lcp;
    };

    auto lcp = buildLCP(s);
    long long N = s.size();
    long long ans = N * (N + 1) / 2;
    for (int i = 1; i < N; ++i) {
        ans -= lcp[i];
    }
    cout << ans << '\n';
}