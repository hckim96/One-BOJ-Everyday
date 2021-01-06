#include <iostream>
#include <cmath>

using namespace std;

int N, R, C;

int cnt = 0;

void search(int sr, int sc, int width) {
    if (width == 1) {
        cnt++;
    } else {
        int nr, nc;
        if (R < sr + width / 2) {
            if (C < sc + width / 2) {
                nr = sr;
                nc = sc;
            } else {
                nr = sr;
                nc = sc + width / 2;
                cnt += width / 2 * width / 2;
            }
        } else {
            if (C < sc + width / 2) {
                nr = sr + width / 2;
                nc = sc;
                cnt += width / 2 * width / 2 * 2;
            } else {
                nr = sr + width / 2;
                nc = sc + width / 2;
                cnt += width / 2 * width / 2 * 3;
            }
        }
        search(nr, nc, width / 2);
    }
}

int main() {
    cin >> N >> R >> C;

    search(0, 0, int(pow(2, N)));

    cout << cnt - 1 << "\n";
}