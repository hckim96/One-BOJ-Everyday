#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // int N;
    // cin >> N;

    // map<int, int> m;
    // while (N--) {
    //     int num;
    //     cin >> num;
    //     ++m[num];
    // }

    // int M;
    // cin >> M;
    // while (M--) {
    //     int num;
    //     cin >> num;
    //     cout << (m.count(num) ? "1 " : "0 ");
    // }

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int M;
    cin >> M;
    while (M--) {
        int num;
        cin >> num;
        auto it = lower_bound(all(a), num);
        if (it == a.end() || *it != num) {
            cout << "0 ";
        } else {
            cout << "1 ";
        }
    }

}