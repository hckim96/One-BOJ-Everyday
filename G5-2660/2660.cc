#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 50


// 회원 점수: 다른 모든 노드들과의 거리 최대 값
int minScore = 987654321;

int scores[N_MAX + 1];

int N;

int adjacencyMatrix[N_MAX + 1][N_MAX + 1];

void bfs(int start) {
    int visited[N_MAX + 1] = {0};

    fill_n(visited, N_MAX + 1, -1);

    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (visited[i] >= 0) {
                continue;
            }

            if (adjacencyMatrix[front][i] != 1) {
                continue;
            }

            q.push(i);
            visited[i] = visited[front] + 1;
        }
    }

    int score = 0;
    for (int i = 1; i <= N; i++) {
        if (i == start) {
            continue;
        }

        if (visited[i] == -1) {
            score = 987654321;
            break;
        }

        score = max(score, visited[i]);
    }
    scores[start] = score;
    minScore = min(minScore, score);

}

int main() {
    cin >> N;

    while (1) {

        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp1 == -1 && tmp2 == -1) {
            break;
        }

        adjacencyMatrix[tmp1][tmp2] = 1;
        adjacencyMatrix[tmp2][tmp1] = 1;
    }

    for (int i = 1; i <= N; i++) {
        bfs(i);
    }

    int candidateCnt = 0;

    for (int i = 1; i <= N; i++) {
        if (scores[i] == minScore) {
            candidateCnt++;
        }
    }

    cout << minScore << " " << candidateCnt << "\n";
    for (int i = 1; i <= N; i++) {
        if (scores[i] == minScore) {
            cout << i << " ";
        }
    }
    cout << "\n";

    return 0;
}