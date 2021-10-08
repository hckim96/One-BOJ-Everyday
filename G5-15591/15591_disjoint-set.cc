#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int myFind(vector<int>& p, int n) {
    if (p[n] < 0) {
        return n;
    }
    return p[n] = myFind(p, p[n]);
}

void myUnion(vector<int>& p, int n1, int n2) {
    int p1 = myFind(p, n1);
    int p2 = myFind(p, n2);

    if (p1 == p2) {
        return;
    }

    p[p2] += p[p1];
    p[p1] = p2;
}

bool cmp(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
    return get<0>(t1) > get<0>(t2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    // r, p, q
    vector<tuple<int, int, int> > edge(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        auto& [r, p, q] = edge[i];
        cin >> p >> q >> r;
    }
    
    // k, v, idx
    vector<tuple<int, int, int> > query(Q);
    for (int i = 0; i < Q; ++i) {
        auto& [k, v, idx] = query[i];
        cin >> k >> v;
        idx = i;
    }


    sort(query.begin(), query.end(), cmp);
    sort(edge.begin(), edge.end(), cmp);

    vector<int> p(N + 1, -1);
    int i = 0;
    vector<int> answer(Q);
    for (auto [k, v, idx]: query) {
        while (i < N - 1) {
            auto [r, n1, n2] = edge[i];
            if (r >= k) {
                myUnion(p, n1, n2);
                ++i;
            } else {
                break;
            }
        }
        answer[idx] = -p[myFind(p, v)] - 1;
    }

    for (auto e: answer) {
        cout << e << '\n';
    }
}