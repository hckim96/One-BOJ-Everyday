#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, Q;

    cin >> N >> Q;

    vector<int> parent(N + 1), p(N + 1);

    for (int i = 2; i <= N; ++i) {
        int num;
        cin >> num;

        parent[i] = num;
    }

    function<int(int)> myFind = [&](int cur) {
        if (p[cur] == 0) {
            return cur;
        }
        return p[cur] = myFind(p[cur]);
    };

    function<void(int, int)> myUnion = [&](int u, int v) {
        int p1 = myFind(u);
        int p2 = myFind(v);

        if (p1 != p2) {
            p[p1] = p2;
        }
    };

    vector<tuple<int, int, int> > query(N - 1 + Q);

    for (int i = 0; i < query.size(); ++i) {
        int x, b, d;
        cin >> x >> b;
        if (x) cin >> d;
        query[i] = {x, b, d};
    }

    vector<int> answer;

    for (int i = query.size() - 1; i >= 0; --i) {
        auto [x, u, v] = query[i];

        if (x) {
            answer.push_back(myFind(u) == myFind(v));
        } else {
            myUnion(u, parent[u]);
        }
    }

    for (int i = answer.size() - 1; i >= 0; --i) {
        if (answer[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}