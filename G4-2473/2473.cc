#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> solution(N);
    
    for (auto & s: solution) {
        cin >> s;
    }

    sort(solution.begin(), solution.end());

    int answerIdx[3] = {0};

    long long answerSum = 3e9;
    for (int i = 0; i < N - 2; i++) {
        int j = i + 1;
        int k = N - 1;

        while (j < k) {
            long long tmpSum = (long long)solution[i] + solution[j] + solution[k];

            if (answerSum > abs(tmpSum)) {
                answerSum = abs(tmpSum);
                answerIdx[0] = i;
                answerIdx[1] = j;
                answerIdx[2] = k;
                if (answerSum == 0) {
                    cout << solution[i] << " " << solution[j] << " " << solution[k] << "\n";
                    return 0;
                }
            }

            if (tmpSum > 0) {
                k--;
            } else {
                j++;
            }
        }
    }

    cout << solution[answerIdx[0]] << " " << solution[answerIdx[1]] << " " << solution[answerIdx[2]] << "\n";
}