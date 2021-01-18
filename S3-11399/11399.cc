#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 1000

int N;
int P[N_MAX] = {0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    int answer = 0;
    for (int i = 1; i < N; i++) {
        P[i] += P[i - 1];
        answer += P[i - 1];
    }
    answer += P[N - 1];
    
    cout << answer << '\n';
}