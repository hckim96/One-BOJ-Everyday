#include <iostream>
#include <vector>

using namespace std;
long long f(vector<int>& arr, vector<int>& len, vector<int>& power, vector<vector<long long> >& dp, int bit, int r) {
    long long& ret = dp[bit][r];

    int N = arr.size();
    int K = dp[0].size();

    if (bit == (1 << N) - 1) {
        if (r) {
            return 0;
        } else {
            return 1;
        }
    }

    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int i = 0; i < N; ++i) {
        if (!(bit & (1 << i))) {
            ret += f(arr, len, power, dp, bit | (1 << i), (r * power[len[i]] + arr[i]) % K);
        }
    }

    return ret;
}

long long gcd(long long l, long long s) {
    if (s == 0) {
        return l;
    }

    return gcd(s, l % s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<string> tmp(N);

    for (auto &e: tmp) {
        cin >> e;
    }

    int K;
    cin >> K;

    vector<int> arr(N);
    vector<int> len(N);
    vector<int> power(51, 0);
    int tmpNum = 1;
    for (int i = 0; i <= 50; ++i) {
        tmpNum %= K;
        power[i] = tmpNum;
        tmpNum *= 10;

    }
    for (int i = 0; i < N; ++i) {
        int num = 0;
        for (auto e: tmp[i]) {
            num *= 10;
            num += e - '0';
            num %= K;
        }
        arr[i] = num;
        len[i] = tmp[i].size();
    }

    vector<vector<long long> > dp(1 << N, vector<long long> (K, -1));

    long long p = f(arr, len, power, dp, 0, 0);
    long long q = 1;
    if (p == 0) {
        q = 1;
    } else {
        for (int i = 1; i <= N; ++i) {
            q *= i;
        }

        long long gcd_ = gcd(q, p);
        p /= gcd_;
        q /= gcd_;
    }

    cout << p << '/' << q << '\n';
}
