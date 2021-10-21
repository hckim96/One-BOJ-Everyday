#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int N;
int mp, mf, ms, mv;
vector<bool> ret;
int minCost = 1e9;

void ff(vector<tuple<int, int, int, int, int> >& vv, vector<bool>& selected, int p, int f, int s, int v, int c, int cur) {
    if (p >= mp && f >= mf && s >= ms && v >= mv) {
        if (minCost > c) {
            minCost = c;
            ret = vector<bool>(selected);
        }
        return;
    }
    if (cur == N) {
        return;
    }

    auto [p1, f1, s1, v1, c1] = vv[cur];
    selected[cur] = true;
    ff(vv, selected, p + p1, f + f1, s + s1, v + v1, c + c1, cur + 1);
    selected[cur] = false;
    ff(vv, selected, p, f, s, v, c, cur + 1);


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    // p f s v c
    vector<tuple<int, int, int, int, int> > vv(N);

    for (auto& [p, f, s, v, c]: vv) {
        cin >> p >> f >> s >> v >> c;
    }

    vector<bool> selected(N, false);
    ff(vv, selected, 0, 0, 0, 0, 0, 0);

    if (minCost == 1e9) {
        cout << "-1\n\n";
        return 0;
    }
    
    cout << minCost << '\n';
    for (int i = 0; i < ret.size(); ++i) {
        if (ret[i]) cout << i + 1 << ' ';
    }
    cout << '\n';
}