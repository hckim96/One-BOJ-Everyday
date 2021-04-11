#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int f(vector<vector<int> >& profit, vector<vector<int> >& invest, vector<vector<int> >& dp, int N, int M) {
    if (M == 0 || N == 0) {
        return 0;
    }

    int& ret = dp[N][M];

    if (ret != -1) {
        return ret;
    }
    
    int tmp = 0;
    for (int i = 0; i <= N; ++i) {
        int ttmp = f(profit, invest, dp, N - i, M - 1) + profit[i][M];
        if (tmp < ttmp) {
            tmp = ttmp;
            invest[N][M] = i;
        }
    }

    return ret = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > profit(N + 1, vector<int> (M + 1, 0));

    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        for (int j = 1; j <= M; ++j) {
            cin >> profit[i][j];
        }
    }
    
    vector<vector<int> > dp(N + 1, vector<int> (M + 1, -1));
    vector<vector<int> > invest(N + 1, vector<int> (M + 1, 0));
    cout << f(profit, invest, dp, N, M) << '\n'; 

    stack<int> st;
    int n = N;
    int m = M;

    while (!(n == 0 && m == 0)) {
        st.push(invest[n][m]);
        n -= invest[n][m];
        --m;
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';
}
