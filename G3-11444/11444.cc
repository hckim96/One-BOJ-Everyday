#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long> > mat;
#define MOD 1000000007LL

mat operator * (mat& a, mat& b) {
    mat ret = {{0, 0}, {0, 0}};
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 2; ++c) {
            for (int k = 0; k < 2; ++k) {
                ret[r][c] += a[r][k] * b[k][c];
            }
            ret[r][c] %= MOD;
        }
    }
    return ret;
}

int main() {
    long long N;
    cin >> N;

    mat a = {{1, 1}, {1, 0}};
    mat answer = {{1, 0}, {0, 1}};

    while (N > 0) {
        if (N % 2 == 1) {
            answer = answer * a;
        }
        a = a * a;
        N /= 2;
    }

    cout << answer[1][0] << '\n';
}