#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long S(vector<long long>& dp, long long num) {
    long long bitNum = (num ? int(log2(num)) : 0) + 1;
    long long ret = 0;
    long long cnt = 0;
    while (--bitNum) {
        if (num & (1LL << bitNum)) {
            ret += dp[bitNum] + cnt * (1LL << bitNum);
            ++cnt;
        }
    }

    ret += cnt + (num % 2) * (cnt + 1);
    return ret;
}

int main() {
    long long A, B;

    cin >> A >> B;

    vector<long long> dp(int(log2(B)) + 1, 0);

    for (int i = 1; i < dp.size(); ++i) {
        dp[i] = 2 * dp[i - 1] + (1LL << (i - 1));
    }

    cout << S(dp, B) - S(dp, A - 1) << '\n';
}
