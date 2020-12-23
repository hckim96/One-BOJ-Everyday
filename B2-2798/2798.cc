#include <iostream>

using namespace std;

#define N_MAX 100

int arr[N_MAX] = {0};
int N, M;
int answer = 0;

void select(int idx, int selected, int sum) {
    if (selected == 3) {
        if (sum <= M) {
            answer = max(answer, sum);
        }
        return;
    }

    if (sum > M) {
        return;
    }

    if (idx >= N) {
        return;
    }

    select(idx + 1, selected, sum);
    select(idx + 1, selected + 1, sum + arr[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    select(0, 0, 0);

    cout << answer << "\n";
}