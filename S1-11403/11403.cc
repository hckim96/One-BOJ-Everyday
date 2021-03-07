#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int> > arr(N, vector<int> (N, INF));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                arr[i][j] = INF;
            }
        }
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k) {
                if (arr[i][k] > arr[i][j] + arr[j][k]) {
                    arr[i][k] = arr[i][j] + arr[j][k];
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] != INF) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << '\n';
    }
}