#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

#define N_MAX 1000

vector<int> parent(N_MAX + 1, -1);

int myFind(int n) {
    if (parent[n] == -1) {
        return n;
    }
    return parent[n] = myFind(parent[n]);
}

void myUnion(int n1, int n2) {
    int p1 = myFind(n1);
    int p2 = myFind(n2);

    if (p1 != p2) {
        parent[p1] = p2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int,int> > godCoord(N + 1);
    vector<tuple<double, int, int> > edge;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        godCoord[i].first = x;
        godCoord[i].second = y;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            edge.push_back({sqrt(pow(godCoord[i].first - godCoord[j].first, 2) + pow(godCoord[i].second - godCoord[j].second, 2)), i, j});
        }
    }

    for (int i = 0; i < M; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        myUnion(n1, n2);
    }

    sort(edge.begin(), edge.end());
    double answer = 0;

    for (auto e: edge) {
        auto [w, i, j] = e;

        if (myFind(i) != myFind(j)) {
            answer += w;
            myUnion(i, j);
        }
    }
    
    cout.precision(2);
    cout << fixed << answer << "\n";
}