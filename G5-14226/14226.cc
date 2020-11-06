#include <iostream>
#include <queue>

using namespace std;

int numInClipboard = 0;
int visited[2001][2001];
int answer;
int S;

void bfs() {
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            visited[i][j] = -1;
        }
    }

    queue<pair<int, int> > q;

    q.push({1, 0});
    visited[1][0] = 0;
    while (!q.empty()) {
        int frontX = q.front().first;
        int frontClip = q.front().second;
        q.pop();
        if (frontX == S) {
            answer = visited[frontX][frontClip];
            return;
        }
        int nextX;
        int nextClip;
        for (int way = 0; way < 3; way++) {
            if (way == 0) {
                nextClip = frontX;
                nextX = frontX;
            } else if (way == 1) {
                if (frontClip == 0) {
                    continue;
                } 
                nextX = frontX + frontClip;
                nextClip = frontClip;
            } else {
                nextX = frontX - 1;
                nextClip = frontClip;
            }

            if (nextX < 0 || nextX >= 2001 || nextClip < 0 || nextClip >= 2001) {
                continue;
            }

            if (visited[nextX][nextClip] != -1) {
                continue;
            }
            q.push({nextX, nextClip});
            visited[nextX][nextClip] = visited[frontX][frontClip] + 1;
        }
    }
}

int main() {
    cin >> S;

    bfs();

    cout << answer << "\n";

    return 0;
}