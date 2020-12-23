#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 1000000

int arr[N_MAX] = {0};
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\n";
    }
}