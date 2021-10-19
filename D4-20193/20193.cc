#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<tuple<int, int, int> > p;

int LEAFSIZE;
vector<int> t;
vector<int> lazy;

int N, K;
void propagate(int n, int ns, int ne) {
    if (lazy[n] != 0) {
        if (n < LEAFSIZE) {
            lazy[n << 1] += lazy[n];
            lazy[n << 1 | 1] += lazy[n];
        }
        t[n] += lazy[n];
        lazy[n] = 0;
    }
}

// [l, r)
void add(int l, int r, int v, int n, int ns, int ne) {
    propagate(n, ns, ne);
    if (r <= ns || ne <= l) return;
    if (l <= ns && ne <= r) {
        lazy[n] += v;
        propagate(n, ns, ne);
        return;
    }

    int mid = ns + ne >> 1;
    add(l, r, v, n << 1, ns, mid);
    add(l, r, v, n << 1 | 1, mid, ne);
    t[n] = max(t[n << 1], t[n << 1 | 1]);
}

bool check(int R) {
    if (R < 0) return false;

    fill(t.begin(), t.end(), 0);
    fill(lazy.begin(), lazy.end(), 0);
    vector<multiset<int> > vms(K + 1, multiset<int>{-INF, INF});

    int idx = 0;
    for (int i = 0; i < p.size(); ++i) {
        auto [x, y, k] = p[i];
        auto it = vms[k].insert(y);
        int l, r;
        l = max(y, *prev(it) + R + 1);
        r = min(y + R, *next(it) - 1) + 1;
        if (l < r) add(l, r, 1, 1, 0, LEAFSIZE);
        if (i > 0) {
            while (get<0>(p[idx]) + R < x) {
                auto [xx, yy, kk] = p[idx];
                auto itt = vms[kk].lower_bound(yy);
                int ll, rr;
                ll = max(yy, *prev(itt) + R + 1);
                rr = min(yy + R, *next(itt) - 1) + 1;
                if (ll < rr) add(ll, rr, -1, 1, 0, LEAFSIZE);
                vms[kk].erase(itt);
                ++idx;
            }
        }
        if (t[1] == K) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    cin >> N >> K;

    p.resize(N);

    for (auto& [x, y, k]: p) {
        cin >> x >> y >> k;
    }

    int base = 1;
    while (base < 250001) {
        base <<= 1;
    }
    LEAFSIZE = base;
    t.resize(LEAFSIZE * 2, 0);
    lazy.resize(LEAFSIZE * 2, 0);

    sort(p.begin(), p.end());

    int lo, hi;
    lo = -1; hi = 250000 - 1;
    int answer;
    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    answer = hi;

    cout << answer << '\n';
}