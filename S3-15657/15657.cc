#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f(vector<int>& arr, vector<int>& selectedArr, int cur, int selectedNum, int M) {
    if (selectedArr.size() == M) {
        for (auto e: selectedArr) {
            cout << e << ' ';
        }
        cout << '\n';
        return;
    }

    if (cur == arr.size()) {
        return; 
    }

    auto tmp = vector<int> (selectedArr);
    tmp.push_back(arr[cur]);
    f(arr, tmp, cur, selectedNum + 1, M);

    f(arr, selectedArr, cur + 1, selectedNum, M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    for (auto &e: arr) {
        cin >> e;
    }

    sort(arr.begin(), arr.end());

    vector<int> selectedArr;

    f(arr, selectedArr, 0, 0, M);
}
