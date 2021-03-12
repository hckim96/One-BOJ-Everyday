#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define INF 1e9

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int> > combination(N + M + 1, vector<int> (N + M + 1, 1));

    for (int i = 2; i <= N + M; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
            if (combination[i][j] > INF) {
                combination[i][j] = INF;
            }
        }
    }

    if (K > combination[N + M][M]) {
        cout << "-1\n";
        return 0;
    }

    string answer;

    while (N && M) {
        if (K <= combination[N + M - 1][M]) {
            answer += 'a';
            --N;
        } else {
            answer += 'z';
            K -= combination[N + M - 1][M];
            --M;
        }
    }

    while (N--) {
        answer += 'a';
    }
    while (M--) {
        answer += 'z';
    }

    cout << answer << '\n';
}