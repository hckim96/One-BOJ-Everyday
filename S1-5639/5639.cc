#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void f(vector<int>& arr, int s, int e) {
    if (s > e) {
        return;
    }

    if (s == e) {
        cout << arr[s] << '\n';
        return;
    }

    int rs = upper_bound(arr.begin() + s, arr.begin() + e + 1, arr[s]) - arr.begin();

    f(arr, s + 1, rs - 1);
    f(arr, rs, e);
    cout << arr[s] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr(10000);

    int num;
    int cnt = 0;
    while (cin >> num) {
        arr[cnt++] = num;
    }

    f(arr, 0, cnt - 1);
}