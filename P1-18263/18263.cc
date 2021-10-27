#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int> > adj;
vector<pair<int, int> > range;

int co = 0;
void f(int n, int parent) {
    range[n].first = co++;
    for (auto child: adj[n]) {
        if (child == parent) continue;
        f(child, n);
    }
    range[n].second = co - 1;
}

// p is ancestor of c
bool isAncestor(int p, int c) {
    return range[p].first <= range[c].first && range[c].second <= range[p].second;
}

vector<int> order;
vector<vector<pair<int, int> > > stor;
vector<tuple<int, int, int> > query;
vector<vector<int> > relatedQueryIdx;
vector<int> T;
vector<int> answer;
void f2(int n, int parent) {
    stor[T[n]].push_back({n, order.size()});
    order.push_back(n);
    for (auto qIdx: relatedQueryIdx[n]) {
        auto [n1, n2, t] = query[qIdx];
        if (stor[t].empty()) continue;
        if (n1 != n) swap(n1, n2);
        
        auto nn = stor[t].back();
        if (nn.first == n) {
            answer[qIdx] = true;
        } else {
            if (!isAncestor(order[nn.second + 1], n2)) {
                answer[qIdx] = true;
            }
        }
    }

    for (auto c: adj[n]) {
        if (c == parent) continue;
        f2(c, n);
    }

    stor[T[n]].pop_back();
    order.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    T.resize(N + 1);
    range.resize(N + 1);
    adj.resize(N + 1);
    query.resize(M);
    relatedQueryIdx.resize(N + 1);
    answer.resize(M, false);
    stor.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> T[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    f(1, 0);

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        query[i] = {a, b, c};
        relatedQueryIdx[a].push_back(i);
        relatedQueryIdx[b].push_back(i);
    }

    f2(1, 0);

    for (auto e: answer) {
        cout << e;
    }    
    cout << '\n';
}