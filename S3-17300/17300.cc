#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int L;
    cin >> L;

    vector<int> v(10);
    vector<set<int> > s = {
        {1, 3},
        {4, 6},
        {7, 9},
        {1, 7},
        {2, 8},
        {3, 9},
        {1, 9},
        {3, 7},
    };

    int prev = 0;
    for (int i = 0; i < L; ++i) {
        int num;
        cin >> num;

        if (prev) {
            for (auto e: s) {
                if (e.count(prev) && e.count(num) && !v[prev + num >> 1]) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }

        if (v[num]) {
            cout << "NO\n";
            return 0;
        }

        v[num] = true;
        prev = num;
    }
    cout << "YES\n";
}