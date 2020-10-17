#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;

int answer = 987654321;
int minButton[1000001];

void bfs() {

    queue<int> q;

    minButton[S] = 0;
    q.push(S);

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        int next;
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                next = front + U;
            } else {
                next = front - D;
            }
            if (next < 1 || next > F) {
                continue;
            }
            if (minButton[next] != -1) {
                continue;
            }

            minButton[next] = minButton[front] + 1;
            if (next == G) {
                break;
            }
            q.push(next);
        }

    }
}

int main() {
    cin >> F >> S >> G >> U >> D;

    for (int i = 0; i < 1000001; i++) {
        minButton[i] = -1;
    }

    bfs();
    if (minButton[G] == -1) {
        cout << "use the stairs" << "\n";
    } else {
        cout << minButton[G] << "\n";
    }
}