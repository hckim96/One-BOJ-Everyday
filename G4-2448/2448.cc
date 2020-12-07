#include <iostream>
#include <string>

using namespace std;

#define WIDTH_MAX 6144
#define HEIGHT_MAX 3072

string base[3] = {
    "  *  ",
    " * * ",
    "*****"
};

char map[HEIGHT_MAX][WIDTH_MAX];

void myPrint(int n, int r, int c) {
    if (n == 3) {
        for (int height = 0; height < n; height++) {
            for (int width = 0; width < 2 * n - 1; width++) {
                map[r + height][c + width] = base[height][width]; 
            }
        }
    } else {
        myPrint(n / 2, r, c + n / 2);
        myPrint(n / 2, r + n / 2, c);
        myPrint(n / 2, r + n / 2, c + n);
    }
}

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    fill(&map[0][0], &map[N - 1][2 * N - 1], ' ');

    myPrint(N, 0, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}