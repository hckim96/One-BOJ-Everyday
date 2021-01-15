#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 1000
#define INF 987654321

int N, M;
int arr[N_MAX][N_MAX] = {0};
vector<vector<int> > visited(N_MAX, vector<int> (N_MAX, INF));
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int answer = 0;

queue<pair<int, int> > q;
void bfs() {

    while (!q.empty()) {
        auto [frontR, frontC] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nextR = frontR + dr[dir];
            int nextC = frontC + dc[dir];

            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) {
                continue;
            }

            if (arr[nextR][nextC] == -1) {
                continue;
            }

            if (visited[nextR][nextC] <= visited[frontR][frontC] + 1) {
                continue;
            }

            visited[nextR][nextC] = visited[frontR][frontC] + 1;
            q.push({nextR, nextC});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1) {
                visited[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 && visited[i][j] == INF) {
                cout << "-1\n";
                return 0;
            }

            if (arr[i][j] != -1) {
                answer = max(answer, visited[i][j]);
            }
        }
    }

    cout << answer << "\n";
}