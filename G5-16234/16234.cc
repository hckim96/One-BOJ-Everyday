#include <iostream>
#include <queue>
#include <list>

using namespace std;

int N, L, R;
int A[50][50];
int answer = 0;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int bfs() {
    int numOfUnion = 0;
    queue<pair<int, int> > myUnion;
    int total = 0;
    bool visited[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) {
                continue;
            }

            total = 0;
            list<pair<int, int> > members;

            total += A[i][j];
            visited[i][j] = true;
            myUnion.push({i, j});
            members.push_back({i, j});

            while (!myUnion.empty()) {
                int frontR = myUnion.front().first;
                int frontC = myUnion.front().second;
                myUnion.pop();
                int nextR, nextC;
                for (int dir = 0; dir < 4; dir++) {
                    nextR = frontR + dr[dir];
                    nextC = frontC + dc[dir];

                    if (0 <= nextR && nextR < N && 0 <= nextC && nextC < N) {
                        if (!visited[nextR][nextC]) {
                            if (L <= abs(A[frontR][frontC] - A[nextR][nextC]) && abs(A[frontR][frontC] - A[nextR][nextC]) <= R) {
                                total += A[nextR][nextC];
                                visited[nextR][nextC] = true;
                                members.push_back({nextR, nextC});
                                myUnion.push({nextR, nextC});
                            }
                        }
                    }
                }
            }

            if (members.size() != size_t(1)) {
                int mean = total / members.size();
                for (auto it = members.begin(); it != members.end(); it++) {
                    A[it -> first][it -> second] = mean;
                }
                numOfUnion++;
            }

        }
    }

    return numOfUnion;

}
int main() {
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    int numOfUnion = bfs();
    while(numOfUnion != 0) {
        answer++;
        numOfUnion = bfs();
    }

    cout << answer << "\n";
}