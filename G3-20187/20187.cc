#include <iostream>
#include <vector>

using namespace std;

enum DIRECTION {
    D, U, RR, L
};

vector<vector<int> > pos = {
    {2, 3, 0, 1},
    {2, 3, 0, 1},
    {1, 0, 3, 2},
    {1, 0, 3, 2},
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    vector<char> cmd(2 * K);

    for (auto& e: cmd) {
        cin >> e;
    }

    vector<vector<int> > answer(1, vector<int> (1));

    cin >> answer[0][0];

    for (auto it = cmd.rbegin(); it != cmd.rend(); ++it) {
        int R = answer.size();
        int C = answer[0].size();

        vector<vector<int> > newAnswer;

        switch (*it) {
            case 'D':
                newAnswer.resize(2 * R, vector<int> (C));
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        newAnswer[R + i][j] = answer[i][j];
                    }
                }
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        newAnswer[R - 1 - i][j] = pos[D][answer[i][j]];
                    }
                }
                break;
            case 'U':
                newAnswer.resize(2 * R, vector<int> (C));
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        newAnswer[i][j] = answer[i][j];
                    }
                }
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        newAnswer[2 * R - 1 - i][j] = pos[U][answer[i][j]];
                    }
                }
                break;
            case 'R':
                newAnswer.resize(R, vector<int> (2 * C));
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        newAnswer[i][C + j] = answer[i][j];
                    }
                }
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        newAnswer[i][C - 1 - j] = pos[RR][answer[i][j]];
                    }
                }
                break;
            case 'L':
                newAnswer.resize(R, vector<int> (2 * C));
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        newAnswer[i][j] = answer[i][j];
                    }
                }
                for (int i = 0; i < R; ++i) {
                    for (int j = 0; j < C; ++j) {
                        newAnswer[i][2 * C - 1 - j] = pos[L][answer[i][j]];
                    }
                }
                break;
        }
        answer = newAnswer;
    }

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[0].size(); ++j) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}