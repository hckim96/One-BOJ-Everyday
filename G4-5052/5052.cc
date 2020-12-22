#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define N_MAX 10000

int T, N;

string arr[N_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + N);

        bool isNo = false;

        for (int i = 0; i < N - 1; i++) {
            if (arr[i].size() == arr[i + 1].size()) {
                continue;
            }

            if (arr[i + 1].find(arr[i]) == 0) {
                isNo = true;
                break;
            }
        }

        if (isNo) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}