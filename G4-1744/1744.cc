#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 10000

int N;
int arr[N_MAX];

bool cmp(int a, int b) {
    if (a > 0 && b > 0) {
        return b < a;
    } else if (a <= 0 && b <= 0) {
        return a < b;
    } else {
        return a > b;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(&arr[0], &arr[0] + N, cmp);

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            answer += arr[i];
            break;
        }
        if ((arr[i] * arr[i + 1] > arr[i] + arr[i + 1]) && ((arr[i] > 0 && arr[i + 1] > 0) || (arr[i] <= 0 && arr[i + 1] <= 0))) {
            answer += arr[i] * arr[i + 1];
            i++;
        } else {
            answer += arr[i];
        }
    }

    cout << answer << "\n";
}