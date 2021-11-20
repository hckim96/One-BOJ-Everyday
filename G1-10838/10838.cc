#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<int> color(N, 0), p(N, 0);
    vector<int> can(N, 0);
    int seq = 0;
    p[0] = -1;
    auto lca = [&](int a, int b) {
        if (a == b) return a;
        ++seq;

        int cnt;
        cnt = 1000;
        while (a && cnt--) {
            can[a] = seq;
            a = p[a];
        }

        cnt = 1000;
        while (b && cnt--) {
            if (can[b] == seq) return b;
            b = p[b];
        }
        return 0;
    };

    while (K--) {

        int r, a, b, c;
        cin >> r >> a >> b;
        if (r == 1) {
            cin >> c;

            auto lca_ = lca(a, b);

            while (a != lca_) color[a] = c, a = p[a];
            while (b != lca_) color[b] = c, b = p[b];
        } else if (r == 2) {
            p[a] = b;
        } else {
            auto lca_ = lca(a, b);

            set<int> s;
            while (a != lca_) s.insert(color[a]), a = p[a]; 
            while (b != lca_) s.insert(color[b]), b = p[b]; 
            cout << s.size() << '\n';
        }
    }
}