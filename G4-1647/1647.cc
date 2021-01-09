#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

#define N_MAX 100000
#define M_MAX 1000000

tuple<int, int, int> edges[M_MAX];
int parent[N_MAX + 1] = {0};
int N, M;

int myFind(int n) {
    if (parent[n] == 0) {
        return n;
    }
    return parent[n] = myFind(parent[n]);
}

bool cmp (tuple<int, int, int> t1, tuple<int, int, int> t2) {
    return get<0>(t1) < get<0>(t2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edges[i] = {C, A, B};
    }

    sort(edges, edges + M, cmp);
    
    int cnt = N;
    int answer = 0;
    for (int i = 0; i < M; i++) {
        auto [w, n1, n2] = edges[i];
        int p1, p2;
        p1 = myFind(n1);
        p2 = myFind(n2);
        if (p1 != p2) {
            // union
            parent[p1] = p2;
            answer += w;
            cnt--;
            if (cnt == 2) {
                break;
            }
        }
    }

    cout << answer << "\n";
}