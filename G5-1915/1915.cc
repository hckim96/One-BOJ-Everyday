#include <iostream>

using namespace std;

int n, m;

int map[1000][1000];
int dp[1000][1000];
int answer = 0;
int main() {
    cin >> n >> m;

    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            map[i][j] = int(tmp[j]) - 48;
            dp[i][j] = int(tmp[j]) - 48;
            answer = max(answer, dp[i][j]);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (map[i][j] == 1) {  
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
            }
            answer = max(answer, dp[i][j]);
        }
    }

    cout <<  answer * answer << "\n";
}