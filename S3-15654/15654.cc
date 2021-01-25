#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 8

int N, M;
int arr[N_MAX] = {0};
int selected[N_MAX] = {0};
void dfs(int selectedNum, string& s) {
    if (selectedNum == M) {
        cout << s << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (selected[i]) {
            continue;
        }
        selected[i] = 1;
        s += ' ' + to_string(arr[i]);
        dfs(selectedNum + 1, s);
        selected[i] = 0;
        s.erase(s.end() - string(' ' + to_string(arr[i])).size(), s.end());
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    string s;

    for (int i = 0; i < N; i++) {
        selected[i] = 1;
        s = to_string(arr[i]);
        dfs(1, s);
        selected[i] = 0;
    }
}