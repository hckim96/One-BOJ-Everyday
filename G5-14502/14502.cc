#include <iostream>
#include <queue>

using namespace std;

#define MAX 8


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;
int answer = 0;

// y, x
vector<pair<int, int> > virus;

void countSafeAreaAndSave(int tmp[][MAX]);
void makeWall(int tmp[][MAX], int madeCnt);
void spreadVirus(int tmp[][MAX]);
void copyMap(int tmp[][MAX], int map[][MAX]);

int main() {

    cin >> N >> M;
    int map[MAX][MAX];
    int tmpMap[MAX][MAX];


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                copyMap(tmpMap, map);
                tmpMap[i][j] = 1;
                makeWall(tmpMap, 1);
                tmpMap[i][j] = 0;

            }
        }
    }
    
    cout << answer << endl;
}


void countSafeAreaAndSave(int tmp[][MAX]) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) {
                cnt++;
            }
        }
    }
    answer = (answer < cnt) ? cnt : answer;

}
void makeWall(int tmp[][MAX], int madeCnt) {
    if (madeCnt == 3) {
        int afterWall[MAX][MAX];
        copyMap(afterWall, tmp);
        spreadVirus(afterWall);
        countSafeAreaAndSave(afterWall);
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                makeWall(tmp, madeCnt + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

void spreadVirus(int tmp[][MAX]) {

    // y, x
    queue<pair<int, int> > q;
    
    for (int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int direction = 0; direction < 4; direction++){
            int y2 = y + dy[direction];
            int x2 = x + dx[direction];

            if (x2 >= 0 && y2 >= 0 && y2 < N && x2 < M) {
                if (tmp[y2][x2] == 0) {
                    tmp[y2][x2] = 2;
                    q.push(make_pair(y2, x2));
                }
            }
        }
    }

}
void copyMap(int tmp[][MAX], int map[][MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tmp[i][j] = map[i][j];
        }
    }
}