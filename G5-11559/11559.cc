#include <iostream>
#include <queue>

using namespace std;

char map[12][6];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int answer = 0;

int bfs() {
    queue<pair<int, int> > target;
    int ret = 0;
    bool visited[12][6] = {0};

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (map[i][j] == '.') {
                continue;
            } else {

                queue<pair<int, int> > q;
                queue<pair<int, int> > backup;
                char color = map[i][j];

                backup.push({i, j});
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    int frontR = q.front().first;
                    int frontC = q.front().second;
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nextR = frontR + dr[dir];
                        int nextC = frontC + dc[dir];

                        if (nextR < 0 || nextR >= 12 || nextC < 0 || nextC >= 6) {
                            continue;
                        }
                        if (visited[nextR][nextC]) {
                            continue;
                        }
                        if (map[nextR][nextC] != color) {
                            continue;
                        }

                        visited[nextR][nextC] = true;
                        q.push({nextR, nextC});
                        backup.push({nextR, nextC});
                    }
                } // while 
                if (backup.size() >= 4) {
                    while (!backup.empty()) {
                        target.push(backup.front());
                        backup.pop();
                    }
                }
            }

        }
    }

    if (!target.empty()) {
        answer++;
        ret = target.size();
    }
    // remove
    while (!target.empty()) {
        int r = target.front().first;
        int c = target.front().second;
        target.pop();
        map[r][c] = '.';
    }

    // move down;
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            if (map[i][j] == '.') {
                continue;
            }
            int nr = i + 1;
            for (; nr < 12; nr++) {
                if (map[nr][j] != '.') {
                    nr--;
                    break;
                }
            }
            if (nr == 12) {
                nr--;
            }
            char tmp = map[i][j];
            map[i][j] = '.';
            map[nr][j] = tmp;
        }
    }
    return ret;
}
int main() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> map[i][j];
        }
    }

    int ret = bfs();
    
    while (ret > 0) {
        ret = bfs();
        
    }
   cout << answer << "\n"; 
}  
