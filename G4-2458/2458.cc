#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 500

int N, M;

struct Student {
    vector<int> prev;
    vector<int> next;    
};

Student student[N_MAX + 1];

bool knowOrder(int idx) {
    
    int cnt = 0;
    
    queue<int> q;
    bool visited[N_MAX + 1] = {0};
    visited[idx] = true;
    q.push(idx);
    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (auto it = student[i].prev.begin(); it != student[i].prev.end(); it++) {
            if (visited[*it]) {
                continue;
            }

            cnt++;
            q.push(*it);
            visited[*it] = true;
        }
    }

    bool visited2[N_MAX + 1] = {0};
    q.push(idx);
    visited2[idx] = true;
    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (auto it = student[i].next.begin(); it != student[i].next.end(); it++) {
            if (visited2[*it]) {
                continue;
            }

            visited2[*it] = true;
            cnt++;
            q.push(*it);
        }
    }

    if (cnt == N - 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        student[a].next.push_back(b);
        student[b].prev.push_back(a);
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if(knowOrder(i)) {
            answer++;
        }
    }

    cout << answer << '\n';
}