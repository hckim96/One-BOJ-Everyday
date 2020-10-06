#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
int X;
char C;

int map[100][100];
queue<pair<int, int> > snake;

queue<pair<int, char> > command;

int time = 0;
int answer = 0;


int main() {
    cin >> N >> K;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < K; i++) {
        int tmpi, tmpj;
        cin >> tmpi >> tmpj;
        map[tmpi - 1][tmpj - 1] = 1; // apple
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> X >> C;
        command.push({X, C});
    }

    pair<int, char> top;
    top = command.front();
    snake.push({0, 0});
    while(1) {
        
    }
}  