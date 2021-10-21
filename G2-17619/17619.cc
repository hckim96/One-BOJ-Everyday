#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<int> p;
int myFind(int n) {
    if (p[n] == -1) {
        return n;
    }
    return p[n] = myFind(p[n]);
}
void myUnion(int n1, int n2) {
    int p1 = myFind(n1);
    int p2 = myFind(n2);

    if (p1 != p2) {
        p[p1] = p2;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, Q;
    cin >> N >> Q;

    p.resize(N + 1, -1);
    vector<tuple<long long, long long, int> > v(N + 1);

    for (int i = 1; i <= N; ++i) {
        auto& [a, b, c] = v[i];
        cin >> a >> b >> c;
        c = i;
    }

    sort(v.begin(), v.end());

    long long l = 0, r = 1e18;
    int cur = 0;

    for (int i = 1; i <= N; ++i) {
        auto [x1, x2, idx] = v[i];

        if (x1 <= r) {
            if (cur == 0) {
                cur = idx;
                l = x1;
                r = x2;
            } else {
                myUnion(cur, idx);
                r = max(r, x2);
            }
        } else {
            cur = idx;
            l = x1;
            r = x2;
        }
    }

    while (Q--) {
        int n1, n2;
        cin >> n1 >> n2;
        cout << (myFind(n1) == myFind(n2)) << '\n';
    }
}