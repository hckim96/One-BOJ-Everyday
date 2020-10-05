#include <iostream>
#include <string.h>

using namespace std;

int N;
bool visited[100][100];
bool visited2[100][100];
enum Color {
    RED,
    GREEN,
    BLUE
};
Color map[100][100];
Color map2[100][100];

int answer = 0;
int answer2 = 0;

void spreadSection(int i, int j) {

    if (i + 1 != N) {
        if (map[i][j] == map[i + 1][j] && !visited[i + 1][j]) {
            visited[i + 1][j] = true;
            spreadSection(i + 1, j);
        }

    }
    if (i - 1 != -1) {
        if (map[i][j] == map[i - 1][j] && !visited[i - 1][j]) {
            visited[i - 1][j] = true;
            spreadSection(i - 1, j);
        }
    }
    if (j + 1 != N) {
        if (map[i][j] == map[i][j + 1] && !visited[i][j + 1]) {
            visited[i][j + 1] = true;
            spreadSection(i, j + 1);
        }
    }
    if (j - 1 != - 1) {
        if (map[i][j] == map[i][j - 1] && !visited[i][j - 1]) {
            visited[i][j - 1] = true;
            spreadSection(i, j - 1);
        }
    }
    visited[i][j] = true;
}
void spreadSection2(int i, int j) {
    if (i + 1 != N) {
        if (map2[i][j] == map2[i + 1][j] && !visited2[i + 1][j]) {
            visited2[i + 1][j] = true;
            spreadSection2(i + 1, j);
        }
    }
    if (i - 1 != -1) {
        if (map2[i][j] == map2[i - 1][j] && !visited2[i - 1][j]) {
            visited2[i - 1][j] = true;
            spreadSection2(i - 1, j);
        }
    }
    if (j + 1 != N) {
        if (map2[i][j] == map2[i][j + 1] && !visited2[i][j + 1]) {
            visited2[i][j + 1] = true;
            spreadSection2(i, j + 1);
        }
    }
    if (j - 1 != -1) {
        if (map2[i][j] == map2[i][j - 1] && !visited2[i][j - 1]) {
            visited2[i][j - 1] = true;
            spreadSection2(i, j - 1);
        }
    }
    visited2[i][j] = true;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string tmpStr;
        cin >> tmpStr;
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            visited2[i][j] = false;
            if (strcmp(tmpStr.substr(j,1).c_str(), "R") == 0) {
                map[i][j] = RED;
                map2[i][j] = RED;
            } else if (tmpStr.substr(j, 1).find("G") != string::npos) {
                map[i][j] = GREEN;
                map2[i][j] = RED;
            } else {
                map[i][j] = BLUE;
                map2[i][j] = BLUE;
            }
        }

    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                spreadSection(i, j);
                answer++;
            }
            if (!visited2[i][j]) {
                spreadSection2(i, j);
                answer2++;
            }
        }
    }
    cout << answer << " " << answer2 << "\n";
}