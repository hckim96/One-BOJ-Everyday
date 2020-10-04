#include <iostream>
#include <vector>

using namespace std;


int N, M, x, y, K;
int map[20][20];
int diceR, diceC;
// 1, 2, 3, 4  동 서 북 남
int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};

// 위 앞 오른쪽
vector<pair<int, int> > dice = {{0, 0}, {0, 0}, {0, 0}};

void exchangePair(int index, int index2) {
    pair<int, int> tmp;
    tmp = dice[index];
    dice[index].swap(dice[index2]);
}

void exchangeInt(int index) {
    int tmp;
    tmp = dice[index].first;
    dice[index].first = dice[index].second;
    dice[index].second = tmp;
}

void roleDice(int command) {
    int tmpR, tmpC;
    tmpR = diceR + dr[command];
    tmpC = diceC + dc[command];

    if (tmpR < 0 || tmpR >= N || tmpC < 0 || tmpC >= M) {
        return;
    } else {
        diceR = tmpR;
        diceC = tmpC;

        switch (command) {
        case 1:
            exchangeInt(2);
            exchangePair(0, 2);
            break;
        case 2:
            exchangeInt(0);
            exchangePair(0, 2);
            /* code */
            break;
        case 3:
            exchangeInt(0);
            exchangePair(0, 1);
            break;
        case 4:
            exchangeInt(1);
            exchangePair(0, 1);
            break;
        default:
            break;
        }

        if (map[diceR][diceC] == 0) {
            map[diceR][diceC] = dice[0].second;
        } else {
            dice[0].second = map[diceR][diceC];
            map[diceR][diceC] = 0;
        }
        cout << dice[0].first << "\n";
    }
}
int main() {
    cin >> N >> M >> x >> y >> K;
    int command;
    diceR = x;
    diceC = y;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> command;
        roleDice(command);
    }
}