#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

struct line {
    long long m, c;
    long long eval(long long x) {return m * x + c;}
    long long intersecX(line l) {return (c - l.c) / (l.m - m);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<pair<long long, long long> > v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(all(v));

    vector<pair<long long, long long> > v2;

    long long prevMax = v.back().second;
    v2.push_back(v.back());
    for (int i = N - 2; i >= 0; --i) {
        if (v[i].second > prevMax) {
            v2.push_back(v[i]);
            prevMax = v[i].second;
        }
    }

    reverse(all(v2));

    deque<line> dq;
    long long ans = 0;
    dq.push_back({v2[0].second, 0});
    for (int i = 0; i < v2.size(); ++i) {
        while (dq.size() >= 2 && dq[0].eval(v2[i].first) >= dq[1].eval(v2[i].first)) dq.pop_front();
        ans = dq.front().eval(v2[i].first);
        ans = dq.front().eval(v2[i].first);
        if (i == v2.size() - 1) break;
        line cur = {v2[i + 1].second, ans};
        while (dq.size() >= 2 && cur.intersecX(dq.back()) <= dq.back().intersecX(dq[dq.size() - 2])) dq.pop_back();
        dq.push_back(cur);
    }

    cout << ans << '\n';
}