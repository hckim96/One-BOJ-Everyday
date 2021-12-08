#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, K;
    cin >> N >> M;
    vector<vector<int> > v1(N, vector<int> (M, 0));
    for (auto& e: v1) for (auto& ee: e) cin >> ee;
    cin >> M >> K;
    vector<vector<int> > v2(M, vector<int> (K, 0));
    for (auto& e: v2) for (auto& ee: e) cin >> ee;

    vector<vector<int> > ret(N, vector<int> (K, 0));

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[0].size(); ++j) {
            for (int k = 0; k < v1[0].size(); ++k) {
                ret[i][j] += v1[i][k] * v2[k][j];
            }
        }
    }

    for (auto e: ret) {
        for (auto ee: e) {
            cout << ee << ' ';
        }
        cout << '\n';
    }
}