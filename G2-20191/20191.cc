#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S, T;
    cin >> S >> T;

    vector<vector<int> > dp(T.size(), vector<int> (26, -1));
    vector<int> v(26, -1);

    for (int i = T.size() - 1; i >= 0; --i) v[T[i] - 'a'] = i;
    for (int j = 0; j < 26; ++j) {
        if (v[j] == -1) continue;
        for (int i = T.size() - 1; i >= 0; --i) {
            dp[i][j] = v[j];
            if (T[i] == char(j + 'a')) v[j] = i;
        }
    }
    
    int it = T.size() - 1;
    int answer = 0;
    for (auto e: S) {
        int nit = dp[it][e - 'a'];
        if (nit == -1) {
            answer = -1;
            break;
        }
        answer += nit <= it;
        it = nit;
    }

    cout << answer << '\n';
}