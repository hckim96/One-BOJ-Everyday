#include <iostream>
#include <vector>

using namespace std;

void f(vector<int>& arr, int N, int M, int cur, int selected) {
    if (selected == M) {
        for (auto e: arr) {
            cout << e << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i <= N; ++i) {
        arr[selected] = i;
        f(arr, N, M, i, selected + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    vector<int> arr(M, 0);

    for (int i = 1; i <= N; ++i) {
        arr[0] = i;
        f(arr, N, M, i, 1);
    }
}