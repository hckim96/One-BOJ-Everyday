#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f(vector<int>& arr, vector<bool>& selected, vector<int>& answer, int idx) {
    if (idx == answer.size()) {
        for (auto e: answer) {
            cout << e << ' ';
        }
        cout << '\n';
        return;
    }

    int neighbor = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (!selected[i] && arr[i] != neighbor) {
            selected[i] = true;
            answer[idx] = arr[i];
            neighbor = arr[i];
            f(arr, selected, answer, idx + 1);
            selected[i] = false;
        }
    }
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
    vector<int> answer(M);
    vector<bool> selected(N, false);

    sort(arr.begin(), arr.end());
    f(arr, selected, answer, 0);
}