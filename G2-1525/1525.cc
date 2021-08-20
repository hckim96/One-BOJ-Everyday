#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    map<string, int> visited;
    string s;
    for (int i = 0; i < 9; ++i) {
        char c;
        cin >> c;
        s += c;
    }

    queue<string> q;
    q.push(s);
    visited[s] = 0;

    while (!q.empty()) {
        string f = q.front();
        q.pop();

        if (f == "123456780") {
            cout << visited[f] << '\n';
            return 0;
        }

        int zeroIdx = f.find('0');
        int fr = zeroIdx / 3;
        int fc = zeroIdx % 3;

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= 3 || nc < 0 || nc >= 3) {
                continue;
            }

            string ss(f);
            swap(ss[3 * nr + nc], ss[3 * fr + fc]);

            if (visited.find(ss) != visited.end()) {
                continue;
            }

            visited[ss] = visited[f] + 1;
            q.push(ss);
        }
    }

    cout << "-1\n";
}