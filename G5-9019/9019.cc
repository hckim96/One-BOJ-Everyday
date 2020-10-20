#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int T, A, B;

// *2 -1 left right
char cmd[4] = {'D', 'S', 'L', 'R'};


int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        
        bool visited[10001] = {0};
        int before[10001] = {0};
        char byCommand[10001];


        queue<int> q;
        q.push(A);
        visited[A] = true;
        before[A] = 987654321;
        while (!q.empty()) {
            if (visited[B]) {
                break;
            }
            int number = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int result;
                switch(cmd[j]) {
                    case 'D':
                        result = (2 * number) % 10000;
                        if (!visited[result]) {
                            visited[result] = true;
                            before[result] = number;
                            byCommand[result] = 'D';
                            q.push(result);
                        }
                        break;
                    case 'S':
                        result = (number == 0) ? 9999 : number - 1;
                        if (!visited[result]) {
                            visited[result] = true;
                            before[result] = number;
                            byCommand[result] = 'S';
                            q.push(result);
                        }
                        break;
                    case 'L':
                        result = ((number * 10) + (number / 1000)) % 10000;
                        if (!visited[result]) {
                            visited[result] = true;
                            before[result] = number;
                            byCommand[result] = 'L';
                            q.push(result);
                        }
                        break;
                    case 'R':
                        result = (number / 10) + (number % 10) * 1000;
                        if (!visited[result]) {
                            visited[result] = true;
                            before[result] = number;
                            byCommand[result] = 'R';
                            q.push(result);
                        }
                        break;
                }
            }

        }

        stack<char> s;

        while (before[B] != 987654321) {
            s.push(byCommand[B]);
            B = before[B];
        }
        string answer("");

        while (!s.empty()) {
            answer += s.top();
            s.pop();
        }
        cout << answer << "\n";
    }

}