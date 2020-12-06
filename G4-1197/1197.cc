#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

#define V_MAX 10000
#define E_MAX 100000

int V, E;
int parent[V_MAX + 1] = {0};
tuple<int, int, int> edge[E_MAX];

int myFind(int n) {
    if (parent[n] == -1) {
        return n;
    } else {
        return parent[n] = myFind(parent[n]);
    }
}

void myUnion(int n1, int n2) {
    int parent1, parent2;

    parent1 = myFind(n1);
    parent2 = myFind(n2);

    if (parent1 != parent2) {
        parent[parent2] = parent1;
    }
    return;
}

int kruskal() {
    int ret = 0;

    for (int i = 0; i < E; i++) {
        int n1, n2, weight;
        tie(weight, n1, n2) = edge[i];

        if (myFind(n1) == myFind(n2)) {
            continue;
        }

        myUnion(n1, n2);
        ret += weight;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        edge[i] = {weight, n1, n2};
    }

    fill_n(parent, V + 1, -1);
    sort(edge, edge + E);

    cout << kruskal() << "\n";
}