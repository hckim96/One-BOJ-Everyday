#include <iostream>
#include <queue>

using namespace std;

int adjacency[11][11] = {0};
int population[11] = {0};

// group[citynum] =  1 , 2 
int group[11] = {0};

int N;
int answer = 987654321;

// bfs
bool check(int groupNum) {

    bool visited[11] = {0};
    int idx = 1;

    while (idx <= N) {
        if (group[idx] == groupNum) {
            break;
        }
        idx++;
    }
    if (idx > N) {
        return false;
    }

    queue<int> q;

    q.push(idx);
    visited[idx] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (adjacency[front][i] == 1 && group[idx] == group[i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (group[i] == groupNum && visited[i] == false) {
            return false;
        }
    }

    return true;

}

// make combination dfs
void dfs(int idx, int selected) {
    if (idx > N) {
        if (!check(1) || !check(2)) {
            return;
        }
        int difference = 0;
        for (int i = 1; i <= N; i++) {
            if (group[i] == 1) {
                difference += population[i]; 
            } else {
                difference -= population[i];
            }
        }
        answer = min(abs(difference), answer);
        return;
    }

    group[idx] = 1;
    dfs(idx + 1, selected);
    group[idx] = 0;

    group[idx] = 2;
    dfs(idx + 1, selected);
    group[idx] = 0;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> population[i + 1];
    }

    for (int i = 0; i < N; i++) {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            int city;
            cin >> city;
            adjacency[i + 1][city] = 1;
        }
    }

    dfs(1, 0);

    if (answer == 987654321) {
        cout << -1 << "\n";
    } else {
        cout << answer << "\n";
    }

}