#include <iostream>
#include <vector>

using namespace std;

#define N_MAX 10000

// to weight
vector<pair<int, int> > weight[N_MAX + 1];
int N;

bool visited[N_MAX + 1] = {0};

pair<int, int> dfs(int n, int distance) {

    pair<int , int> ret = {n, distance};
    
    for (auto it = weight[n].begin(); it != weight[n].end(); it++) {
        if (!visited[it -> first]) {
            visited[it -> first] = true;
            pair<int, int> tmp = dfs(it -> first, distance + it -> second);
            visited[it -> first] = false;
            if (tmp.second > ret.second) {
                ret = tmp;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        weight[p].push_back({c, w});
        weight[c].push_back({p, w});
    }

    pair<int, int> ret;

    visited[1] = true;
    ret = dfs(1, 0);

    fill_n(visited, N + 1, false);

    visited[ret.first] = true;
    ret = dfs(ret.first, 0);
    
    cout << ret.second << "\n";
}