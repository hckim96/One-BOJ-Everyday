#include <iostream>
#include <list>

using namespace std;

#define N_MAX 2000
#define M_MAX 2000

list<int> adjacency[N_MAX];

int N, M;

int answer = 0;
bool visited[N_MAX] = {0};

void dfs(int current, int edgeCnt) {
    if (answer == 1) {
        return;
    }

    if (edgeCnt == 4) {
        answer = 1;
        return;
    }

    for (auto it = adjacency[current].begin(); it != adjacency[current].end(); it++) {
        if (!visited[*it]) {
            visited[*it] = true;
            dfs(*it, edgeCnt + 1);
            visited[*it] = false;
        }
    }

}
int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        adjacency[tmp1].push_back(tmp2);
        adjacency[tmp2].push_back(tmp1);
    }

    for (int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    cout << answer << "\n";
}