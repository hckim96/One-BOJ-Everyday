#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<int> > s(N, vector<int> (N, 0));

    for (auto& e: s) for (auto& ee: e) cin >> ee;

    int answer = 1e9;

    vector<int> selected(N, false);
    function<void(int, int)> f = [&](int selectedCnt, int cur) {
        if (selectedCnt == N / 2) {

            int sum1 = 0;
            int sum2 = 0;
            for (int i = 0; i < selected.size(); ++i) {
                for (int j = 0; j < selected.size(); ++j) {
                    if (selected[i] && selected[j]) {
                        sum1 += s[i][j];
                    } else if (!selected[i] && !selected[j]) {
                        sum2 += s[i][j];
                    }
                }
            }    
            answer = min(answer, abs(sum1 - sum2));
            return;
        }

        if (cur == N) {
            return;
        }

        selected[cur] = true;
        f(selectedCnt + 1, cur + 1);
        selected[cur] = false;
        f(selectedCnt, cur + 1);
    };

    f(0, 0);

    cout << answer << '\n';
}