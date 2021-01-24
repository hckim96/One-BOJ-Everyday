#include <iostream>

using namespace std;

#define N_MAX 8

int check[N_MAX + 1] = {0};
int N, M;

void dfs(int num, int selected, string& s) {
    if (selected == M) {
        cout << s << "\n";
        return;
    }

    if (num > N) {
        return;
    }

    s = s + ' ' + to_string(num);
    dfs(num + 1, selected + 1, s);
    s.erase(s.end() - 2, s.end());
    dfs(num + 1, selected, s);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    string s;
    for (int i = 1; i <= N; i++) {
        s = to_string(i);
        dfs(i + 1, 1, s);
    }
}