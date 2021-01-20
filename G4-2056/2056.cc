#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 10000

int N;
int timeNeeded[N_MAX + 1] = {0};
int dp[N_MAX + 1] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        int t, cnt, num;

        cin >> t >> cnt;

        timeNeeded[i] = t;
        dp[i] = t;
        int tmp = 0;
        for (int j = 0; j < cnt; j++) {
            cin >> num;

            tmp = max(tmp, dp[num]);
        }
        dp[i] += tmp; 
        answer = max(answer, dp[i]);
    }

    cout << answer << "\n";

}