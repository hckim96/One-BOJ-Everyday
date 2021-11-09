#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int counter = 0;
    vector<int> dTime(N + 1, 0);
    vector<vector<int> > dfsChild(N + 1);

    vector<int> in(N + 1), part(N + 1), toP(N + 1);

    function<void(int, int)> f = [&](int cur, int p) {
        dTime[cur] = ++counter;

        for (auto e: adj[cur]) {
            if (e == p) continue;

            if (!dTime[e]) {
                dfsChild[cur].push_back(e);
                
                int tmp = in[cur];
                f(e, cur);
                // e 밑에서 cur 에 꽂히는 애들 in[cur] 에 증가됨
                toP[e] = in[cur] - tmp;
                in[cur] += in[e];
                part[cur] += part[e];
            } else if (dTime[e] < dTime[cur]) {
                ++part[cur];
                ++in[e];
            }
        }
    };

    f(1, -1);

    long long answer = 0;
    for (int i = 1; i <= N; ++i) {
        bool isAns = true;
        for (auto ch: dfsChild[i]) {
            if (in[ch] || part[ch] - toP[ch] - in[ch] >= 2) {
                isAns = false;
                break;
            }
        }
        if (M - part[i] - N + 1 > 0) isAns = false;
        if (isAns) answer += i;
    }
    
    cout << answer << '\n';
}