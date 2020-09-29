#include <iostream>
#include <vector>

using namespace std;

int N, M, r, c, d;

int answer = 0;

// 왼쪽방향 -> (currentdirection + 3) % 4;
vector<pair<int, int> > dOfDirection = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main () {
    cin >> N >> M;
    cin >> r >> c >> d;

    int** map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int robotRow = r;
    int robotCol = c;
    int robotDirection = d;
    bool canClean = false;
    pair<int, int> leftTile;
    while (true) {

        if (map[robotRow][robotCol] == 0) {
            // 2 for cleaned
            map[robotRow][robotCol] = 2;
            answer++;
        }

        for (int i = robotDirection + 3; i < robotDirection + 15; i += 3) {
            if (map[robotRow + dOfDirection[i % 4].first][robotCol + dOfDirection[i % 4].second] == 0) {
                robotDirection = i % 4;
                canClean = canClean || true;
                break;
            } else {
                canClean = canClean || false;
            }
        }

        if (canClean) {
        // 전진 후 1번 
        robotRow += dOfDirection[robotDirection].first;
        robotCol += dOfDirection[robotDirection].second;
        canClean = false;

        } else {
        // 후진하거나 종료
            int backRow = robotRow + dOfDirection[(robotDirection + 6) % 4].first;
            int backCol = robotCol + dOfDirection[(robotDirection + 6) % 4].second;
            if (map[backRow][backCol] == 1) {
                cout << answer << "\n";
                return 0;
            } else {
                robotRow = backRow;
                robotCol = backCol;
            }
        }

    }

}