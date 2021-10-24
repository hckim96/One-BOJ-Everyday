#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    deque<deque<int> > posOfColor(N + 1);

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        posOfColor[y].push_back(x);
    }

    long long answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (posOfColor[i].size()) {
            sort(posOfColor[i].begin(), posOfColor[i].end());
            for (int j = 0; j < posOfColor[i].size(); ++j) {
                int tmp = 1e9;

                if (j - 1 >= 0) tmp = min(tmp, posOfColor[i][j] - posOfColor[i][j - 1]);
                if (j + 1 < posOfColor[i].size()) tmp = min(tmp, posOfColor[i][j + 1] - posOfColor[i][j]);
                answer += tmp;
            }
        }
    }

    cout << answer << '\n';
}