#include <iostream>
#include <list>

using namespace std;

int arr[101] = {0};
bool visited[101] = {0};
list<int> answer;

int N;

void dfs(int startNodeNum, int currentNodeNum) {

    // 시작노드가 사이클을 이루는 노드인지
    if (startNodeNum == currentNodeNum) {
        if (visited[startNodeNum]) {
            answer.push_back(startNodeNum);
            return;
        }
    }

    // 종료 조건
    if (visited[currentNodeNum]) {
        return;
    }

    visited[currentNodeNum] = true;
    dfs(startNodeNum, arr[currentNodeNum]);
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        dfs(i, i);
        fill_n(visited, 101, 0);
    }

    cout << answer.size() << "\n";
    for (auto it = answer.begin(); it != answer.end(); it++) {
        cout << *it << "\n";
    }
}