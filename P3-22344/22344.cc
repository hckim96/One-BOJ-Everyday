#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const long long INF = 1e18;

    int N, M;
    cin >> N >> M;

    vector<vector<pair<long long, long long> > > adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<long long> a(N + 1, 0), k(N + 1, 0);
    queue<int> q;
    a[1] = 1;
    q.push(1);

    bool flag = false;
    long long x = INF;
    while (!q.empty() && !flag) {
        auto f = q.front();
        q.pop();

        for (auto [n, c]: adj[f]) {
            if (a[n]) {
                if (x == INF) {
                    if (a[f] == a[n]) {
                        double tmp = (double)(c - (k[f] + k[n])) / (a[f] + a[n]);
                        if (tmp - (long long)tmp != 0) {
                            flag = true;
                            break;
                        } else {
                            x = tmp;
                        }
                    } else {
                        if (k[f] + k[n] != c) {
                            flag = true;
                            break;
                        }
                    }
                } else {
                    if (x * (a[f] + a[n]) + k[n] + k[f] != c) {
                        flag = true;
                        break;
                    }
                }
                continue;
            }

            a[n] = -a[f];
            k[n] = c - k[f];
            q.push(n);
        }
    }

    if (flag) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    if (x != INF) {
        for (int i = 1; i <= N; ++i) {
            cout << a[i] * x + k[i] << ' ';
        }
        cout << '\n';
    } else {
        vector<long long> v;
        for (int i = 1; i <= N; ++i) {
            v.push_back(-k[i] / a[i]);
        }
        sort(v.begin(), v.end());

        vector<long long> vCopy(v);
        v.erase(unique(v.begin(), v.end()), v.end());

        vector<long long> cnt(v.size());

        vector<long long> sum(v.size(), 0);
        for (int i = 0; i < v.size(); ++i) {
            cnt[i] = upper_bound(vCopy.begin(), vCopy.end(), v[i]) - lower_bound(vCopy.begin(), vCopy.end(), v[i]);
            if (i) {
                sum[i] = sum[i - 1] + cnt[i];
            } else {
                sum[i] = cnt[i];
            }
        }

        int idx = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (sum[v.size() - 1] - 2 * sum[i] <= 0) {
                idx = i;
                break;
            }
        }
        for (int i = 1; i <= N; ++i) {
            cout << a[i] * v[idx] + k[i] << ' ';
        }
        cout << '\n';
    }
}