#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<set<int> > arr(N + 1, set<int> ());
    queue<int> q;
    vector<int> indegree(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        int prev, now;
        for (int j = 0; j < num; ++j) {
            cin >> now;
            if (j) {
                arr[prev].insert(now);
            }
            prev = now;
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (auto e: arr[i]) {
            ++indegree[e];
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> answer;

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        answer.push_back(f);

        for (auto e: arr[f]) {
            --indegree[e];
            if (indegree[e] == 0) {
                q.push(e);
            }
        }
    }

    if (answer.size() != N) {
        cout << "0\n";
        return 0;
    }

    for (auto e: answer) {
        cout << e << '\n';
    }    
}