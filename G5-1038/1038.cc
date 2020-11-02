#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long answer = -1;

vector<long long> v;

void dfs(long long n) {

    if (n > 9876543210) {
        return;
    }

    for (int i = 0; i < (n % 10); i++) {
        v.push_back(n * 10 + i);
        dfs(n * 10 + i);
    }
}

int main() {
    cin >> N;

    if (N > 1022) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < 10; i++) {
            v.push_back(i);
            dfs(i);
        }
        sort(v.begin(), v.end());
        answer = v[N];
        cout << answer << "\n";
    }
}