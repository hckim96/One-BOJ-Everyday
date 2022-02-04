#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<int> p;
    vector<long long> weight;
    function<int(int)> myFind = [&](int n) {
        if (p[n] == -1) return n;
        int pp = myFind(p[n]);
        weight[n] += weight[p[n]];
        return p[n] = pp;
    };
    auto myUnion = [&](int n1, int n2) {
        int p1 = myFind(n1);
        int p2 = myFind(n2);

        if (p1 == p2) return;
        p[p1] = p2;
    };
    
    int N, M;
    while (cin >> N >> M && N) {
        p.resize(N + 1, -1);
        fill_n(p.begin(), p.size(), -1);
        weight.resize(N + 1, 0);
        fill_n(weight.begin(), weight.size(), 0);
        while (M--) {
            char op;
            int a, b;
            long long w;
            cin >> op >> a >> b;
            int p1 = myFind(a);
            int p2 = myFind(b);
            if (op == '!') {
                cin >> w;
                if (p1 != p2) {
                    p[p2] = p1;
                    weight[p2] = weight[a] - weight[b] + w;
                }
            } else {
                if (p1 == p2) {
                    cout << weight[b] - weight[a] << '\n';
                } else {
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
}