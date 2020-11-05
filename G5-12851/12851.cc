#include <iostream>
#include <queue>

using namespace std;

int N, K;

int answerSec = -1, answerCnt = 0;
int visited[100001] = {0};

void bfs() {

    queue<int> q;

    visited[N] = 0;
    q.push(N);

    int frontX, nextX;
    while (!q.empty()) {
        frontX = q.front();
        q.pop();

        if (visited[K] != -1 && visited[frontX] >= visited[K]) {
            if (answerCnt == 0) {
                answerCnt++;
            }
            break;
        }

        for (int dir = 0; dir < 3; dir++) {
            if (dir == 0) {
                nextX = frontX - 1;
            } else if (dir == 1) {
                nextX = frontX + 1;
            } else {
                nextX = frontX * 2;
            }

            if (nextX < 0 || nextX >= 100001) {
                continue;
            }
            
            if (visited[nextX] != -1 && visited[nextX] <= visited[frontX]) {
                continue;
            }
            
            if (nextX == K) {
                answerCnt++;
            }

            visited[nextX] = visited[frontX] + 1;
            q.push(nextX);
        }

    }

}

int main() {
    cin >> N >> K;

    fill_n(visited, 100001, -1);

    bfs();

    answerSec = visited[K];

    cout << answerSec << "\n" << answerCnt << "\n";

}