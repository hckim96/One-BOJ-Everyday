#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<int> > D(M, vector<int> (N));

    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            D[i][j] = s[j] - '0';
        }
    }

    // 출
    vector<vector<int> > arr(M, vector<int> (N));
    
    int answer = 0;
    for (int i = 0; i < M; ++i) {
        arr[i][0] = D[i][0];
    }

    for (int j = 1; j < N; ++j) {
        for (int i = 0; i < M; ++i) {

            arr[i][j] = arr[i][j - 1];
            if (i - 1 >= 0) arr[i][j] = max(arr[i][j], arr[i - 1][j - 1]);
            if (i + 1 < M) arr[i][j] = max(arr[i][j], arr[i + 1][j - 1]);

            answer = max(answer, arr[i][j]);
            arr[i][j] = arr[i][j] + D[i][j];
        }
    }

    cout << answer << '\n';
}