#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > arr(4, vector<int> (N));

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < 4; ++i) {
            cin >> arr[i][j];
        }
    }

    vector<int> v1(N * N);
    vector<int> v2(N * N);

    int idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            v1[idx] = arr[0][i] + arr[1][j];
            v2[idx] = arr[2][i] + arr[3][j];
            ++idx;
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int l = 0;
    int r = N * N;

    long long answer = 0;
    while (l != N * N && r != 0) {
        int num = v1[l];
        
        int cnt1 = 0;
        int cnt2 = 0;

        while (l != N * N && v1[l] == num) {
            ++l;
            ++cnt1;
        }

        while (r != 0 && v2[r - 1] > -num) {
            --r;
        }
        while (r != 0 && v2[r - 1] == -num) {
            --r;
            ++cnt2;
        }

        answer += 1LL * cnt1 * cnt2;
    }

    cout << answer << '\n';
}