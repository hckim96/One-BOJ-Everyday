#include <iostream>

using namespace std;


int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int numOfCase[4];
double notSimple = 0;
double visited[29][29] = {0};
int N;

void dfs(int r, int c, int cnt) {

    if (cnt == N) {
        return;
    }

    int nextR, nextC;
    for (int dir = 0; dir < 4; dir++) {
        nextR = r + dr[dir];
        nextC = c + dc[dir];
        if (visited[nextR][nextC] > 0) {
            notSimple += visited[r][c] * (numOfCase[dir] / 100.0);
            continue;
        }

        visited[nextR][nextC] = visited[r][c] * (numOfCase[dir] / 100.0);
        dfs(nextR, nextC, cnt + 1);
        visited[nextR][nextC] = 0;
    }    
}

int main() {
    cin >> N;
    for (int i = 0; i < 4; i++) {
        cin >> numOfCase[i];
    }

    visited[14][14] = 1;
    dfs(14, 14, 0);

    cout.precision(10);
    cout << 1 - notSimple << endl;
}