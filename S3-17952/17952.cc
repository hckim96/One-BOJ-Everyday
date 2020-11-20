#include <iostream>
#include <stack>

using namespace std;

// score, time
stack<pair<int, int> > assignment;

int N;
int totalScore = 0;
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int flag, A, T;
        cin >> flag;
        if (flag == 0) {
            if (assignment.empty()) {
                continue;
            } else {
                int frontA, frontT;
                frontA = assignment.top().first;
                frontT = assignment.top().second;
                assignment.pop();

                frontT--;
                if (frontT == 0) {
                    totalScore += frontA;
                } else {
                    assignment.push({frontA, frontT});
                }
            }
        } else {
            cin >> A >> T;
            if (T == 1) {
                totalScore += A;
            } else {
                assignment.push({A, T - 1});
            }
        }
    }

    cout << totalScore << "\n";
}