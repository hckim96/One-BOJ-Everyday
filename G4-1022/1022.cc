#include <iostream>
#include <algorithm>

using namespace std;

int arr[50][5] = {0};

int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

int r1, c1, r2, c2;
int maxSize = 0;

void makeMap() {
    int layer = 0;
    int sr = 0;
    int sc = 0;
    int val = 1;
    if (r1 <= sr && sr <= r2 && c1 <= sc && sc <= c2) {
        arr[sr - r1][sc - c1] = val;
        maxSize = max(maxSize, int(to_string(arr[sr - r1][sc - c1]).size()));

    }
    int dir = 0;

    int r = sr + dr[dir];
    int c = sc + dc[dir];
    layer++;
    dir = (dir + 1) % 4;
    int cnt = 0;
    while (true) {
        cnt++;
        val++;
        if (r1 <= r && r <= r2 && c1 <= c && c <= c2) {
            arr[r - r1][c - c1] = val;
            maxSize = max(maxSize, int(to_string(arr[r - r1][c - c1]).size()));
        }
        if (val == (2 * layer + 1) * (2 * layer + 1)) {
            if (layer == 5000) {
                return;
            }

            r += dr[dir];
            c += dc[dir];
            dir = (dir + 1) % 4;
            cnt = 0;
            layer++;
            continue;
        }
        if (cnt == layer * 2) {
            dir = (dir + 1) % 4;
            cnt = 0;
        }
        r += dr[dir];
        c += dc[dir];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r1 >> c1 >> r2 >> c2;

    makeMap();

    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++) {

            cout << string(maxSize - int(to_string(arr[i][j]).size()), ' ') << arr[i][j] << " ";
        }
        cout << "\n";
    }
}