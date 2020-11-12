#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 100000

int solution[N_MAX] = {0};
int N;

// difference = 987654321; 로 하면 왜 런타임에러 뜸?
int difference = INT32_MAX;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> solution[i];
    }

    sort(solution, solution + N);

    int idx1, idx2, i, j;
    i = 0; j = N - 1;

    int diffTmp;
    while (i < j) {

        diffTmp = solution[i] + solution[j];

        if (abs(diffTmp) < difference) {
            difference = abs(diffTmp);
            idx1 = i;
            idx2 = j;
        }

        if (diffTmp > 0) {
            // j 가 너무 오른쪽이다
            j--;
        } else {
            i++;
        }
    }

    cout << solution[idx1] << " " <<  solution[idx2] << "\n";
    return 0;
}