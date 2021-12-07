#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<vector<vector<long long> > > dp(101, vector<vector<long long> > (101, vector<long long> (101, -1e18)));

    function<long long(int, int, int)> f = [&](int a, int b, int c) {

        long long& ret = dp[a][b][c];

        if (ret != -1e18) {
            return ret;
        }
        
        if (a <= 50 || b <= 50 || c <= 50) {
            return ret = 1;
        } 
        if (a > 70 || b > 70 || c > 70) {
            return ret = f(70, 70, 70);
        }

        if (a < b && b < c) {
            return ret = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
        }

        return ret = f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
    };

    int a, b, c;

    while (cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1)) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << f(a + 50, b + 50, c + 50) << '\n';
    }
}