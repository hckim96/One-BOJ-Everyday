#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > arr(N, vector<int> (M));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }

    int answer = 0;

    for (int case_ = 0; case_ < (1 << N*M); ++case_) {
        int caseSum = 0;
        for (int i = 0; i < N; ++i) {
            int partitionSum = 0;
            for (int j = 0; j < M; ++j) {
                if ((case_ & (1 << (i * M + j))) == 0) {
                    partitionSum *= 10;
                    partitionSum += arr[i][j];
                } else {
                    caseSum += partitionSum;
                    partitionSum = 0;
                }
            }
            caseSum += partitionSum;
        }

        for (int j = 0; j < M; ++j) {
            int partitionSum = 0;
            for (int i = 0; i < N; ++i) {
                if ((case_ & (1 << (i * M + j))) == (1 << (i * M + j))) {
                    partitionSum *= 10;
                    partitionSum += arr[i][j];
                } else {
                    caseSum += partitionSum;
                    partitionSum = 0;
                }
            }
            caseSum += partitionSum;
        }

        answer = max(answer, caseSum);
    }
    cout << answer << '\n';
}