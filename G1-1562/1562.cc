#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000
int N;

int f(vector<vector<vector<int> > >& dp, int left, int selected, int prev) {
    if (!left) {
        if (selected == (1 << 10) - 1) {
            return 1;
        } else {
            return 0;
        }
    }

    int& ret = dp[left][selected][prev];

    if (ret != -1 && left != N) {
        return ret;
    }

    ret = 0;
    if (left == N) {
        for (int i = 1; i <= 9; ++i) {
            ret = (0LL + ret + f(dp, left - 1, selected | (1 << i), i)) % MOD;
        }
    } else {
        if (prev - 1 >= 0) {
            ret = (0LL + ret + f(dp, left - 1, selected | (1 << (prev - 1)), prev - 1)) % MOD;
        }

        if (prev + 1 <= 9) {
            ret = (0LL + ret + f(dp, left - 1, selected | (1 << (prev + 1)), prev + 1)) % MOD;
        }
    }

    return ret;
}

int main() {
    cin >> N;

    if (N < 10) {
        cout << "0\n";
        return 0;
    }

    vector<vector<vector<int> > > dp(N + 1, vector<vector<int> > (1 << 10, vector<int> (10, -1)));

    cout << f(dp, N, 0, 0) << '\n';
}
