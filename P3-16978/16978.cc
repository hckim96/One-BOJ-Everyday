#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<long long> a(N), t(2 * N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        t[N + i] = a[i];
    }

    for (int i = N - 1; i >= 1; --i) {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }

    auto sum = [&](int l, int r) {
        long long ret = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret += t[l++];
            if (r & 1) ret += t[--r];
        }
        return ret;
    };

    auto update = [&](int p, long long val) {
        for (t[p += N] = val; p > 1; p >>= 1) {
            t[p >> 1] = t[p] + t[p ^ 1];
        }
    };

    int M;
    cin >> M;
    vector<pair<int, long long> > q1;
    map<int, vector<tuple<int, int, int> > > q2;

    for (int i = 0; i < M; ++i) {
        long long a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            --b;
            q1.push_back({b, c});
        } else {
            cin >> b >> c >> d;
            --c; --d;
            q2[b].push_back({i, c, d});
        }
    }

    int done = -1;
    vector<pair<int, long long> > answer;
    for (auto it = q2.begin(); it != q2.end(); ++it) {
        for (int i = done + 1; i < it -> first; ++i) {
            update(q1[i].first, q1[i].second);
        }

        done = it -> first - 1;

        for (auto [i, l, r]: it -> second) {
            answer.push_back({i, sum(l, r + 1)});
        }
    }

    sort(all(answer));
    
    for (auto e: answer) {
        cout << e.second << '\n';
    }
}