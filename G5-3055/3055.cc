#include <iostream>
#include <queue>

using namespace std;

int R, C;

// 0, 1, 2, 3, 4  빔 물 돌 굴, 고
int map[50][50];
int answer = 987654321;
queue<pair<int, int> > water;
int GoR,GoC;
// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
void dfs(int GoR, int GoC, int time) {
    if (map[GoR][GoC] == 3) {
        answer = min(answer, time);
        return;
    }

    while (1) {
        int s = water.size();
        while (s--) {
            int frontR = water.front().first;
            int frontC = water.front().second;

        }
    }
    //spread water
}

void moveGo(int direction) {

}
int main() {
    cin >> R >> C;
    char tmp;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> tmp;
            switch (tmp) {
                case '.':
                //empty
                    map[i][j] = 0;
                    break;
                case '*':
                // water
                    map[i][j] = 1;
                    water.push({i, j});
                    break;
                case 'X':
                // rock
                    map[i][j] = 2;
                    break;
                case 'D':
                // gool
                    map[i][j] = 3;
                    break;
                case 'S':
                    map[i][j] = 4;
                    GoR = i;
                    GoC = j;
                    break;
                default:
                    return 1;
                    break;
            }
        }
    }

    dfs(GoR, GoC, 0);

    cout << answer << "\n";


}