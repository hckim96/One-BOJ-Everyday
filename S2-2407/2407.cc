#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N_MAX 100

string dp[N_MAX + 1][N_MAX + 1];

string big_add(string s1, string s2) {
    int sum = 0;
    string result;
    while (!s1.empty() || !s2.empty() || sum) {
        if (!s1.empty()) {
            sum += s1.back() - '0';
            s1.pop_back();
        }
        if (!s2.empty()) {
            sum += s2.back() - '0';
            s2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string myCombination(int n, int m) {
    if (n == m || m == 0) {
        return "1";
    }

    if (dp[n][m] != "") {
        return dp[n][m];
    }

    return dp[n][m] = big_add(myCombination(n - 1, m - 1), myCombination(n - 1, m));
}

int main() {

    int N, M;
    cin >> N >> M;

    cout << myCombination(N, M) << "\n";
}