#include <iostream>
#include <vector>

using namespace std;

long long answer = 0;
long long N;

long long f(vector<vector<int> >& adj, int cur, int parent) {
    long long ret;
    ret = 0;
    for (auto e: adj[cur]) {
        if (e == parent) continue;
        long long tmp = 1 + f(adj, e, cur);
        answer += tmp * (2 * N - tmp - 1) / 2;
        ret += tmp;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<vector<int> > adj(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    f(adj, 1, 0);

    cout << answer << '\n';
}