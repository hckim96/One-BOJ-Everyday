#include <iostream>

using namespace std;

int N, M, H;

// 1~N번 1~H번
int line[12][31];


// 0, 1, 2, 3
int needToAdd = 0;
int answer = 987654321;

bool check() {
    int start;
    int now;
    for (int i = 1; i <= N; i++) {
        start = i;
        now = start;
        for (int h = 1; h <= H; h++) {
            if (line[now][h] == 1) {
                now++;
            } else if (line[now - 1][h] == 1) {
                now--;
            }
        }
        if (now != start) {
            return false;
        }
    }
    return true;
}

// idx = 0 ~ [N][H] .. 
void dfs(int numToAdd, int added, int idx) {
    if (numToAdd == added) {
        if (check()) {
            answer = min(answer, added);
            return;
        }
        return;
    }
    if ((idx / (H + 1)) == N + 1) {
        return;
    }
    while (idx < (N + 1) * (H + 1)) {
        if ((idx / (H + 1)) == 0 || (idx % (H + 1)) == 0) {
            idx++;
            continue;
        } 
        if (line[idx / (H + 1)][idx % (H + 1)] == 0 && line[(idx / (H + 1)) - 1][idx % (H + 1)] == 0 && line[(idx / (H + 1)) + 1][idx % (H + 1)] == 0) {
            line[idx / (H + 1)][idx % (H + 1)] = 1;
            dfs(numToAdd, added + 1, idx + 1);
            line[idx / (H + 1)][idx % (H + 1)] = 0;
        }
        idx++;
    }
}

int main() {
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        line[b][a] = 1;
    }

    for (int i = 0; i <= 3; i++) {
        dfs(i, 0, 0);
    }

    if (answer == 987654321) {
        cout << -1 << "\n";
    } else {
        cout << answer << "\n";
    }
}