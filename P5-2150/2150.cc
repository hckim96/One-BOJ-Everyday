#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void visit(vector<vector<int> >& adj_rev, vector<bool>& visited, vector<int>& tmp, int v) {
    if (!visited[v]) {
        visited[v] = true;
        for (auto e: adj_rev[v]) {
            visit(adj_rev, visited, tmp, e);
        }
        tmp.push_back(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<vector<int> > adj(V + 1, vector<int> ());
    vector<vector<int> > adj_rev(V + 1, vector<int> ());

    for (int i = 0; i < E; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj_rev[v2].push_back(v1);
    }

    for (int i = 1; i <= V; ++i) {
        sort(adj[i].begin(), adj[i].end());
        sort(adj_rev[i].begin(), adj_rev[i].end());
    }

    vector<bool> visited(V + 1, false);
    vector<int> L;

    for (int i = 1; i <= V; ++i) {
        visit(adj, visited, L, i);
    }

    vector<vector<int> > answer;

    int answerCnt = 0;
    fill(visited.begin(), visited.end(), false);

    for (auto it = L.rbegin(); it != L.rend(); ++it) {
        if (!visited[*it]) {
            vector<int> tmp;
            visit(adj_rev, visited, tmp, *it);
            sort(tmp.begin(), tmp.end());
            tmp.push_back(-1);        
            answer.push_back(tmp);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';

    for (auto e: answer) {
        for (auto ee: e) {
            cout << ee << ' ';
        }
        cout << '\n';
    }
}
