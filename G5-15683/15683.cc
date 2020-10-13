#include <iostream>

using namespace std;

struct CCTV {
    int r;
    int c;
    int type;
};

int N, M;
int map[8][8];
CCTV cctv[8];
int numOfCCTV = 0;

// 6 벽 1 ~ 5 cctv

int answer = 987654321;
void mapCopy(int dest[8][8], int src[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dest[i][j] = src[i][j];
        }
    }
}
void watch(int dir, int r, int c);
void dfs(int cctvIdx) {
    if (cctvIdx == numOfCCTV) {
        // check safe area  and save if smaller
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) {
                    cnt++;
                }
            }
        }
        answer = min(answer, cnt);
        return;
    }

    int before[8][8];
    mapCopy(before, map);
    for (int dir = 0; dir < 4; dir++) {
        switch (cctv[cctvIdx].type) {
            case 1: // 4
                mapCopy(before, map);
                watch(dir, cctv[cctvIdx].r, cctv[cctvIdx].c);
                dfs(cctvIdx + 1);
                mapCopy(map, before);
                break;
            case 2: // 2
                if (dir == 0 || dir == 1) {
                    mapCopy(before, map);
                    watch(dir, cctv[cctvIdx].r, cctv[cctvIdx].c);
                    watch(dir + 2, cctv[cctvIdx].r, cctv[cctvIdx].c);
                    dfs(cctvIdx + 1);
                    mapCopy(map, before);
                }
                break;
            case 3: // 4
                mapCopy(before, map);
                watch(dir, cctv[cctvIdx].r, cctv[cctvIdx].c);
                watch(dir + 1, cctv[cctvIdx].r, cctv[cctvIdx].c);
                dfs(cctvIdx + 1);
                mapCopy(map, before);
                break;
            case 4: // 4
                mapCopy(before, map);
                watch(dir, cctv[cctvIdx].r, cctv[cctvIdx].c);
                watch(dir + 1, cctv[cctvIdx].r, cctv[cctvIdx].c);
                watch(dir + 2, cctv[cctvIdx].r, cctv[cctvIdx].c);
                dfs(cctvIdx + 1);
                mapCopy(map, before);
                break;
            case 5: // 0
                if (dir == 0) {
                    mapCopy(before, map);
                    watch(dir, cctv[cctvIdx].r, cctv[cctvIdx].c);
                    watch(dir + 1, cctv[cctvIdx].r, cctv[cctvIdx].c);
                    watch(dir + 2, cctv[cctvIdx].r, cctv[cctvIdx].c);
                    watch(dir + 3, cctv[cctvIdx].r, cctv[cctvIdx].c);
                    dfs(cctvIdx + 1);
                    mapCopy(map, before);
                }
                break;
            default:
                break;
        }
    }

}
// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
void watch(int dir, int r, int c) {
    dir = dir % 4;

    r += dr[dir];
    c += dc[dir];
    while (1) {
        if (r < 0 || r >= N || c < 0 || c >= M) {
            break;
        }
        if (map[r][c] == 6) {
            break;
        }

        if (map[r][c] != 0) {
            r += dr[dir];
            c += dc[dir];
            continue;
        } else {
            map[r][c] = 9;
        }
    }

}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0 && map[i][j] != 6) {
                cctv[numOfCCTV].type = map[i][j];
                cctv[numOfCCTV].r = i;
                cctv[numOfCCTV].c = j;
                numOfCCTV++;
            }
        }
    }

    dfs(0);

    cout << answer << "\n";
}   