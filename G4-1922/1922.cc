#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

#define N_MAX 1000
#define M_MAX 100000

int N, M;
tuple<int, int, int> edge[M_MAX];
int parent[N_MAX + 1] = {0};

int myFind(int n) {
    if (parent[n] == -1) {
        return n;
    } else {
        return parent[n] = myFind(parent[n]);
    }
}

void myUnion(int n1, int n2) {
    int p1, p2;
    p1 = myFind(n1);
    p2 = myFind(n2);

    if (p1 != p2) {
        parent[p1] = p2;
    }
    return;
}

int kruskal() {
    int ret = 0;

    for (int i = 0; i < M; i++) {
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
    
    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int n1, n2, weight;

        cin >> n1 >> n2 >> weight;

        edge[i] = {weight, n1, n2};
    }

    fill_n(parent, N + 1, -1);
    sort(edge, edge + M);

    cout << kruskal() << "\n"; 

    return 0;
}