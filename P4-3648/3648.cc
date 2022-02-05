#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    while (cin >> N >> M) {
        vector<vector<int> > adj(2 * N + 1), adj_rev(2 * N + 1);
        vector<int> visited(2 * N + 1, false);
        vector<int> group(2 * N + 1, 0);

        for (int i = 0; i < M; ++i) {
            int n1, n2;
            cin >> n1 >> n2;
            adj[N - n1].push_back(N + n2); // not n1 -> n2
            adj[N - n2].push_back(N + n1); // not n2 -> n1
            adj_rev[N + n2].push_back(N - n1);
            adj_rev[N + n1].push_back(N - n2);    
        }

        // x1 should be true, x1 V x1
        adj[N - 1].push_back(N + 1); 
        adj[N - 1].push_back(N + 1); 
        adj_rev[N + 1].push_back(N - 1);
        adj_rev[N + 1].push_back(N - 1);    

        vector<int> st;
        function<void(vector<vector<int> >&, int, int)> getSCC = [&](vector<vector<int> >& adj, int cur, int groupNum) {
            visited[cur] = true;
            for (auto e: adj[cur]) {
                if (!visited[e]) getSCC(adj, e, groupNum);
            }
            if (groupNum) {
                group[cur] = groupNum;
            } else {
                st.push_back(cur);
            }
        };

        for (int i = 0; i <= 2 * N; ++i) {
            if (i == N) continue;
            if (!visited[i]) getSCC(adj, i, 0);
        }

        fill(all(visited), false);

        int groupSeq = 1;
        for (auto rit = st.rbegin(); rit != st.rend(); ++rit) {
            if (!visited[*rit]) getSCC(adj_rev, *rit, groupSeq++);
        }

        bool possible = true;
        for (int i = 1; i <= N; ++i) {
            if (group[N + i] == group[N - i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}