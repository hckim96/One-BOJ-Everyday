#include <iostream>

using namespace std;

int N;
int answer = 0;
int* row;

bool isPromising(int rowNum);
void dfs(int rowNum);

int main() {
    cin >> N;
    row = new int[N];

    dfs(0);

    delete[] row;
    cout << answer <<endl;
}


// rowNum 까지 유망한지 검사
bool isPromising(int rowNum) {
    // 위, 왼위, 오위 대각선 방향만 검사하면 됨.
    for (int i = 1; i <= rowNum; i++) {
        if (row[rowNum - i] == row[rowNum] || row[rowNum - i] == row[rowNum] - i || row[rowNum - i] == row[rowNum] + i) {
            return false;
        }
    }

    return true;
}

void dfs(int rowNum) {
    if (rowNum == N) {
        answer++;
        return;
    }
    for (int i = 0; i < N; i++) {
        row[rowNum] = i;
        if (isPromising(rowNum)) { // pruning
            dfs(rowNum + 1);
        }
    }
}