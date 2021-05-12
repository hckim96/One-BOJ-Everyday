#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int myFind(int n) {
    int& ret = parent[n];

    while (ret != parent[ret]) {
        ret = parent[ret];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    parent.resize(N + 1);

    for (int i = 1; i < N; ++i) {
        parent[i] = i + 1;
    }

    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        parent[tmp] = tmp;
    }

    for (int i = 0; i < K; ++i) {
        int c;
        cin >> c;

        int p = myFind(c + 1);
        cout << p << '\n';
        parent[p] = p + 1;
    }
}
