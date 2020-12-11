#include <iostream>
#include <vector>

using namespace std;

#define X_MAX 100

vector<pair<int, int> > dragonCurve[11];

bool map[X_MAX + 1][X_MAX + 1] = {0};

int N;

int countRectangle() {
    int ret = 0;
    for (int x = 0; x < X_MAX; x++) {
        for (int y = 0; y < X_MAX; y++) {
            if (map[x][y] && map[x + 1][y] && map[x][y + 1] && map[x + 1][y + 1]) {
                ret++;
            }
        }
    }
    return ret;
}

void checkDragonCurve(int startX, int startY, int d, int g) {
    for (auto it = dragonCurve[g].begin(); it != dragonCurve[g].end(); it++) {
        auto [x, y] = *it;
        for (int i = 0; i < (4 - d) % 4; i++) {
            int tmp = x;
            x = -1 * y;
            y = tmp;
        }

        x = x + startX;
        y = y + startY;

        if (x < 0 || x > X_MAX || y < 0 || y > X_MAX) {
            continue;
        }

        map[x][y] = true;
    }
}

void makeDragonCurve(int g) {
    if (g == 0) {
        dragonCurve[g].push_back({0, 0});
        dragonCurve[g].push_back({1, 0});
        return;
    }

    dragonCurve[g] = dragonCurve[g - 1];
    for (auto it = ++dragonCurve[g - 1].rbegin(); it != dragonCurve[g - 1].rend(); it++) {
        auto [x, y] = *it;
        auto [xBase, yBase] = *(--dragonCurve[g - 1].end());
        dragonCurve[g].push_back({-(y - yBase) + xBase, x - xBase + yBase});
    }
    return;
}

int main() {
    cin >> N;

    for (int i = 0; i < 11; i++) {
        makeDragonCurve(i);
    }

    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        checkDragonCurve(x, y, d, g);
    }

    cout << countRectangle() << "\n";

    return 0;
}