#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define COORD_MAX 100000

vector<int> answer;
int myPrev[2 * COORD_MAX + 1];

int N, K;

void bfs() {
    queue<int> q;
    int visited[2 * COORD_MAX + 1] = {0};
    q.push(N);
    visited[N] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == K) {
            cout << visited[K] - 1 << "\n";

            int tmp = x;
            answer.push_back(tmp);
            while (tmp != N) {
                tmp = myPrev[tmp];
                answer.push_back(tmp);
            }

            for (auto rit = answer.rbegin(); rit != answer.rend(); rit++) {
                cout << *rit << " ";
            }
            cout << "\n";
            return;
        }

        for (int i = -1; i < 2; i++) {
            int nx;

            if (i == 0) {
                nx = 2 * x;
            } else {
                nx = x + i; 
            }

            if (nx < 0 || nx > 2 * COORD_MAX) {
                continue;
            }
            if (visited[nx] > 0) {
                continue;
            }

            q.push(nx);
            visited[nx] = visited[x] + 1;
            myPrev[nx] = x;

        }
    }
}

int main() {
    cin >> N >> K;

    bfs();
}