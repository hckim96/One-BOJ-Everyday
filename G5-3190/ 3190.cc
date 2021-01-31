#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
int X;
char C;

int map[100][100];
queue<pair<int, int> > snake;
// 0, 1, 2, 3  북 동 남 서
int snakeDirection = 1;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, char> > command;

int currentTime = 0;
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
    pair<int, int> head = snake.back();
    pair<int, int> tail = snake.front();
    
    map[head.first][head.second] = 2; // 2 for snake
    
    while(1) {
        if (top.first == currentTime) {
            // change direction
            if (top.second == 'D') {
                snakeDirection = (snakeDirection + 1) % 4;
            } else if(top.second == 'L') {
                snakeDirection = (snakeDirection + 3) % 4;
            }
            command.pop();
            if (!command.empty()) {
                top = command.front();
            } else {
                top = {0, 'C'};
            }
        }
        
        // move 
        snake.push({head.first + dr[snakeDirection], head.second + dc[snakeDirection]});
        head = snake.back();
        currentTime++;
        if (head.first < 0 || head.first >= N || head.second < 0 || head.second >= N) {
            cout << currentTime << "\n";
            return 0;
        }

        if (map[head.first][head.second] == 0) { 
            // empty
            map[head.first][head.second] = 2;
            map[tail.first][tail.second] = 0;
            snake.pop();
            tail = snake.front();

        } else if (map[head.first][head.second] == 2) {
            // snake body
            cout << currentTime << "\n";
            return 0;

        } else {
            map[head.first][head.second] = 2;

        }
    }
}  