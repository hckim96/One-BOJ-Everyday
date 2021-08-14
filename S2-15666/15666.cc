#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void f(vector<int>& arr, vector<int>& answer, int idx, int selected) {
    if (answer.size() == selected) {
        for (auto e: answer) {
            cout << e << ' ';
        }
        cout << '\n';
        return;
    }
    if (idx == arr.size()) {
        return;
    }

    answer[selected] = arr[idx];
    f(arr, answer, idx, selected + 1);
    f(arr, answer, idx + 1, selected);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    for (auto& e: arr) {
        cin >> e;
    }

    sort(arr.begin(), arr.end());

    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    vector<int> answer(M);

    f(arr, answer, 0, 0);
}