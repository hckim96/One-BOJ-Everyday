#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int T, start, goal;
int cost[10001];
bool isPrime[10001]; // false
int answer = -1;

void checkPrime() {
    fill(isPrime, isPrime + sizeof(isPrime) / sizeof(bool) - 1, true);

    for (int divisor = 2; divisor <= 10000; divisor++) {
        if (!isPrime[divisor]) {
            continue;
        }
        for (int multiple = divisor * divisor; multiple <= 10000; multiple += divisor) {
            isPrime[multiple] = false;
        }
    }
}

void bfs() {

    queue<int> q;

    q.push(start);

    while (!q.empty()) {
        if (cost[goal] != -1) {
            answer = cost[goal];
            return;
        }

        int now = q.front();
        string string_now = to_string(now);
        q.pop();

        int next;
        for (int digit = 0; digit < 4; digit++) {
            for (int j = 0; j < 10; j++) {
                string string_next(string_now);
                string_next.replace(digit, 1, to_string(j));
                next = stoi(string_next);

                if (next == now || next < 1000) {
                    continue;
                }

                if (cost[next] != -1) {
                    continue;
                }

                if (isPrime[next]) {
                    cost[next] = cost[now] + 1;
                    q.push(next);
                }
            }
        }
    }
}


int main() {
    cin >> T;
    checkPrime();
    for (int i = 0; i < T; i++) {
        cin >> start >> goal;
        
        //init
        fill(cost, cost + sizeof(cost) / sizeof(int) - 1, -1);
        cost[start] = 0;
        answer = -1;

        bfs();

        if (answer == -1) {
            cout << "Impossible" << "\n";
        } else {
            cout << answer << "\n";
        }
    }


    return 0;
}