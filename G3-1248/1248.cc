#include <iostream>
#include <vector>

using namespace std;

bool gotAnswer = false;

bool isValid(vector<vector<char> >& S, vector<int>& prefixSum, int idx) {
    for (int i = 1; i < idx; ++i) {
        int j = idx;
        
        int partSum = prefixSum[j] - prefixSum[i - 1];

        if ((S[i][j] == '+' && partSum <= 0) || (S[i][j] == '0' && partSum != 0) || (S[i][j] == '-' && partSum >= 0)) {
            return false;
        }
    }

    return true;
}

void f(vector<int>& A, vector<vector<char> >& S, vector<int>& prefixSum, int idx) {
    if (gotAnswer) {
        return;
    }
    if (idx == A.size()) {
        gotAnswer = true;
        return;
    }

    int s, e;
    if (S[idx][idx] == '+') {
        s = 1;
        e = 10;
    } else if (S[idx][idx] == '0') {
        s = 0;
        e = 0;
    } else {
        s = -10;
        e = -1;
    }

    for (int num = s; num <= e; ++num) {
        if (gotAnswer) {
            return;
        }

        A[idx] = num;
        prefixSum[idx] = prefixSum[idx - 1] + A[idx];
        if (isValid(S, prefixSum, idx)) {
            f(A, S, prefixSum, idx + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N + 1, 0);
    vector<int> prefixSum(N + 1, 0);
    vector<vector<char> > S(N + 1, vector<char> (N + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            cin >> S[i][j];
        }
    }

    f(A, S, prefixSum, 1);

    for (int i = 1; i <= N; ++i) {
        cout << A[i] << ' ';
    }
    cout << '\n';
}