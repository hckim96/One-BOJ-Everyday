#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 10

int N;
int alphabetCnt[26] = {0};

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        int m = 1;
        for (auto it = tmp.rbegin(); it != tmp.rend(); it++) {
            alphabetCnt[(*it) - 'A'] += m;
            m *= 10;
        }
    }

    sort(alphabetCnt, alphabetCnt + 26, greater<int>());

    int sum = 0;
    for (int i = 9; i > 0; i--) {
        sum += alphabetCnt[9 - i] * i;
    }

    cout << sum << "\n";
}