#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 500000

int N, M;
int num[N_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num, num + N);
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        cout << upper_bound(num, num + N, n) - lower_bound(num, num + N, n) << " ";
    }
}