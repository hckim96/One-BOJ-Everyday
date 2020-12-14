#include <iostream>
#include <vector>

using namespace std;

#define N_MAX 100000

int T;
int N;

int want[N_MAX + 1] = {0};
bool visited[N_MAX + 1] = {0};
bool counted[N_MAX + 1] = {0};
int answer = 0;

void dfs(int now) {
    visited[now] = true;

    int next = want[now];
    if (visited[next]) {
        if (!counted[next]) {
            while (next != now) {
                answer--;
                next = want[next];
            }
            answer--;
        }
    } else {
        dfs(next);
    }
    counted[now] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> want[i];
        }

        fill_n(visited, N + 1, 0);
        fill_n(counted, N + 1, 0);
        answer = N;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << answer << "\n";
    }
}