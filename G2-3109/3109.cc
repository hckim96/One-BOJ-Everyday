#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

bool f(vector<string>& arr, int r, int c) {
    if (r < 0 || r >= arr.size() || c < 0 || c >= arr[0].size()) {
        return false;
    }

    if (arr[r][c] == 'x') {
        return false;
    }

    if (c == arr[0].size() - 1) {
        ++answer;
        return true;
    }

    arr[r][c] = 'x';

    return f(arr, r - 1, c + 1) || f(arr, r, c + 1) || f(arr, r + 1, c + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;
    
    vector<string> arr(R);
    for (auto& e: arr) {
        cin >> e;
    }

    for (int i = 0; i < R; ++i) {
        f(arr, i, 0);
    }
    cout << answer << '\n';
}