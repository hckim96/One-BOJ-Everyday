#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> cost;

int myFind(int n) {
    if (parent[n] == -1) {
        return n;
    }
    return parent[n] = myFind(parent[n]);
}

void myUnion(int n1, int n2) {
    int p1, p2;
    p1 = myFind(n1);
    p2 = myFind(n2);

    if (p1 != p2) {
        if (cost[p1] < cost[p2]) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;

    cin >> N >> M >> K;

    parent.resize(N + 1, -1);
    cost.resize(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
    }

    for (int i = 0; i < M; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        myUnion(n1, n2);
    }

    int minCost = 0;
    for (int i = 1; i <= N; ++i) {
        int p1, p2;
        p1 = myFind(0);
        p2 = myFind(i);
        if (p1 != p2) {
            minCost += cost[p2];
            myUnion(p1, p2);
        }
    }

    if (minCost <= K) {
        cout << minCost << '\n';
    } else {
        cout << "Oh no\n";
    }
}