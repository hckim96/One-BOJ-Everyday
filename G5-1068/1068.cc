#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > adj(N, vector<int> (N));

    queue<int> q;

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        if (n != -1) {
            adj[n][i] = 1;
        } else {
            q.push(i);
        }
    }

    int deleteN;
    cin >> deleteN;

    for (int i = 0; i < N; ++i) {
        if (adj[i][deleteN] == 1) {
            adj[i][deleteN] = 0;
        }
    }

    int answer = 0;

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        if (f == deleteN) {
            continue;
        }

        bool flag = true;
        for (int i = 0; i < N; ++i) {
            if (adj[f][i]) {
                q.push(i);
                flag = false;
            }
        }

        if (flag) {
            ++answer;
        }
    }

    cout << answer << '\n';
}