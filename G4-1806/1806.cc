#include <iostream>

using namespace std;

#define N_MAX 100000

int arr[N_MAX + 1] = {0};
int N, S;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int start,end;
    int answer = 987654321;

    start = 1;
    end = 2;
    long long partSum = arr[1];

    // s ~ e - 1
    while (start < end && end <= N + 1) {
        if (partSum < S) {
            if (end == N + 1) {
                break;
            }
            partSum += arr[end];
            end++;
        } else {
            answer = min(answer, end - start);
            partSum -= arr[start];
            start++;
        }
    }

    if (answer == 987654321) {
        cout << "0\n";
    } else {
        cout << answer << "\n";
    }
}