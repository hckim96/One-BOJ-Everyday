#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const long long TENFAC = 3628800;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<tuple<int, long long, int> > > adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B, L, K;
        cin >> A >> B >> L >> K;

        adj[A].push_back({B, TENFAC * L, K});
        adj[B].push_back({A, TENFAC * L, K});
    }

    vector<vector<long long> > minTime(N + 1, vector<long long> (11, INF));

    struct cmp {
        bool operator()(tuple<long long, int, int>& t1, tuple<long long, int, int>& t2) {
            return get<0>(t2) < get<0>(t1);
        }
    };

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int> >, cmp> pq;
    minTime[1][1] = 0;
    pq.push({0, 1, 1});

    long long answer = INF;

    while (pq.size()) {
        auto [ft, fn, fv] = pq.top();
        pq.pop();

        if (ft > minTime[fn][fv]) continue;
        if (fn == N) {
            answer = min(answer, ft);
            continue;
        }
        for (int plus = -1; plus <= 1; ++plus) {
            int nv = fv + plus;
            if (nv < 1 || nv > 10) continue;
            for (auto [nn, l, k]: adj[fn]) {
                if (nv > k) continue;
                if (minTime[nn][nv] > ft + l / nv) {
                    minTime[nn][nv] = ft + l / nv;
                    pq.push({minTime[nn][nv], nn, nv});
                }
            }
        }
    }
    long long ans1 = answer / TENFAC;
    cout << ans1;
    answer %= TENFAC;
    stringstream ss;
    ss << fixed << setprecision(9) << (long double)answer / TENFAC;
    cout << ss.str().substr(1) << '\n';
}
