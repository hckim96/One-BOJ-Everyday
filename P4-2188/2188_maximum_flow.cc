#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, capacity, flow;
    Edge* dual;

    Edge() {}
    Edge(int _to, int _capacity) {
        to = _to;
        capacity = _capacity;
        flow = 0;
    }

    int residual() {
        return capacity - flow;
    }

    void addFlow(int f) {
        flow += f;
        dual -> flow -= f;
    }
};

void addEdge(vector<vector<Edge* > >& adj, int u, int v, int c) {
    auto uv = new Edge(v, c);
    auto uv_dual = new Edge(u, 0);
    uv -> dual = uv_dual;
    uv_dual -> dual = uv;
    adj[u].push_back(uv);
    adj[v].push_back(uv_dual);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int S = 0;
    int T = 2 * N - 1 > 2 * M ? 2 * N : 2 * M + 1;

    vector<vector<Edge*> > adj(T + 1);

    for (int i = 1; i <= M; ++i) {
        int v = 2 * i;
        addEdge(adj, v, T, 1);
    }
    
    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cnt;
        int u = 2 * i - 1;
        addEdge(adj, S, u, 1);
        for (int j = 0; j < cnt; ++j) {
            int num;
            cin >> num;
            int v = 2 * num;
            addEdge(adj, u, v, 1);
        }
    }

    int answer = 0;

    while (true) {
        queue<int> q;
        q.push(S);
        vector<Edge*> prev(T + 1, nullptr);

        while (!q.empty() && !prev[T]) {
            auto f = q.front();
            q.pop();

            for (auto e: adj[f]) {
                if (prev[e -> to]) {
                    continue;
                }

                if (e -> residual() <= 0) {
                    continue;
                }

                if (e -> to == S) {
                    continue;
                }

                q.push(e -> to);
                prev[e -> to] = e;
                if (prev[T]) {
                    break;
                }
            }
        }

        if (prev[T]) {
            auto cur = prev[T];
            while (cur) {
                cur -> addFlow(1);
                cur = prev[cur -> dual -> to];
            }
            ++answer;
        } else {
            break;
        }
    }

    cout << answer << '\n';
}