#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parent;

int myFind(int n) {
    if (parent[n] == -1) {
        return n;
    }

    return parent[n] = myFind(parent[n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    parent.resize(N);
    fill(parent.begin(), parent.end(), -1);

    vector<pair<int, int> > X(N);
    vector<pair<int, int> > Y(N);
    vector<pair<int, int> > Z(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i].first >> Y[i].first >> Z[i].first;
        X[i].second = Y[i].second = Z[i].second = i;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    vector<tuple<int, int, int> > edge(6 * (N - 1));
    int idx = 0;
    for (int i = 0; i < N - 1; ++i) {
        edge[idx++] = {abs(X[i].first - X[i + 1].first) , X[i].second, X[i + 1].second};
        edge[idx++] = {abs(Y[i].first - Y[i + 1].first) , Y[i].second, Y[i + 1].second};
        edge[idx++] = {abs(Z[i].first - Z[i + 1].first) , Z[i].second, Z[i + 1].second};

    }

    long long answer = 0;
    sort(edge.begin(), edge.end());
    int cnt = 0;

    for (auto e: edge) {
        auto [c, i, j] = e;

        int p1 = myFind(i);
        int p2 = myFind(j);

        if (p1 != p2) {
            answer = answer + c;
            ++cnt;
            if (cnt == N - 1) {
                break;
            }

            parent[p1] = p2;
        }
    }

    cout << answer << '\n';
}
