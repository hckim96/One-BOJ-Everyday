#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define N_MAX 1000000

pair<int, int> arr[N_MAX];
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = {tmp, i};
    }

    sort(&arr[0], &arr[0] + N);

    int idx = 0;
    int num = arr[0].first;

    vector<int> answer(N);

    for (int i = 0; i < N; i++) {
        if (arr[i].first > num) {
            num = arr[i].first;
            idx++;
            answer[arr[i].second] = idx;
        } else {
            answer[arr[i].second] = idx;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}