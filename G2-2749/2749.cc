#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000

vector<vector<int> > operator*(vector<vector<int> > v1, vector<vector<int> > v2) {
    vector<vector<int> > ret(v1.size(), vector<int> (v2[0].size(), 0));
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[0].size(); ++j) {
            for (int k = 0; k < v1[0].size(); ++k) {
                ret[i][j] = (0LL + ret[i][j] + 1LL * v1[i][k] * v2[k][j]) % MOD;
            }
        }
    }

    return ret;
}

int main() {
    unsigned long long N;
    cin >> N;

    --N;

    vector<vector<int> > ret = {{1, 0}, {0, 1}};

    vector<vector<int> > mul = {{1, 1}, {1, 0}};

    while (N) {
        if (N & 1) {
            ret = ret * mul;
        }

        mul = mul * mul;
        N >>= 1;
    }

    cout << ret[0][0] << '\n';
}