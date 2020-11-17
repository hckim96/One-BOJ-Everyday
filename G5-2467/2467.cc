#include <iostream>

using namespace std;

#define N_MAX 100000

int solution[N_MAX] = {0};

int N;
int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> solution[i];
    }


    int i, j;
    i = 0;
    j = N - 1;

    int absSum = INT32_MAX;

    int answer1, answer2;
    while (i < j) {
        int tmpSum = solution[i] + solution[j];

        if (abs(tmpSum) < absSum) {
            answer1 = solution[i];
            answer2 = solution[j];
            absSum = abs(tmpSum);
        }

        if (tmpSum >= 0) {
            j--;
        }
        if (tmpSum < 0) {
            i++;
        }

    }
    
    cout << answer1 << " " << answer2 << "\n";

}