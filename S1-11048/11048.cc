#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > a(N, vector<int> (M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int num = 0;
            if (i) a[i][j] = max(a[i][j], a[i - 1][j]);
            if (j) a[i][j] = max(a[i][j], a[i][j - 1]);
            if (i && j) a[i][j] = max(a[i][j], a[i - 1][j - 1]);
            cin >> num;
            a[i][j] += num;
        }
    }

    cout << a[N - 1][M - 1] << '\n';
}