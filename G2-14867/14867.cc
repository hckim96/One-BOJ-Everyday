#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    queue<pair<int, int> > q;
    map<pair<int, int>, int> m;
    q.push({0, 0});
    m[{0, 0}] = 0;

    while (!q.empty()) {
        auto [fa, fb] = q.front();
        q.pop();
        
        int ft = m[{fa, fb}];
        if (fa == c && fb == d) {
            cout << ft << '\n';
            return 0;
        }
        
        int na, nb;

        na = a, nb = fb;
        if (m.count({na, nb}) == 0) {
            q.push({na, nb});
            m[{na, nb}] = ft + 1;
        }
        na = fa, nb = b;
        if (m.count({na, nb}) == 0) {
            q.push({na, nb});
            m[{na, nb}] = ft + 1;
        }
        na = 0, nb = fb;
        if (m.count({na, nb}) == 0) {
            q.push({na, nb});
            m[{na, nb}] = ft + 1;
        }
        na = fa, nb = 0;
        if (m.count({na, nb}) == 0) {
            q.push({na, nb});
            m[{na, nb}] = ft + 1;
        }
        na = max(0, fa - (b - fb)), nb = fb + min(b - fb, fa);
        if (m.count({na, nb}) == 0) {
            q.push({na, nb});
            m[{na, nb}] = ft + 1;
        }
        na = fa + min(a - fa, fb), nb = max(0, fb - (a - fa));
        if (m.count({na, nb}) == 0) {
            q.push({na, nb});
            m[{na, nb}] = ft + 1;
        }
    }
    cout << "-1\n";
}