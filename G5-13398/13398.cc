#include <iostream>

using namespace std;

#define N_MAX 100000


int N;

int front[N_MAX], rear[N_MAX];

int arr[N_MAX];

int answer = -987654321;

int main() {

    cin >> N;


    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    front[0] = arr[0];
    rear[N - 1] = arr[N - 1];

    answer = max(answer, front[0]);

    for (int i = 1; i < N; i++) {
        front[i] = max(front[i - 1] + arr[i], arr[i]);
        rear[N - 1 - i] = max(rear[N - 1 - i + 1] + arr[N - 1 - i], arr[N - 1 - i]);
        answer = max(answer, front[i]);

    }

    for(int i = 1; i < N - 1; i++) {
        answer = max(answer, front[i - 1] + rear[i + 1]);
    }
    cout << answer << endl;
    return 0;
}