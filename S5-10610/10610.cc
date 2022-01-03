#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> cnt(10, 0);

    long long digitSum = 0;
    for (int i = 0; i < s.size(); ++i) {
        ++cnt[s[i] - '0'];
        digitSum += s[i] - '0';
    }

    if (cnt[0] == 0 || digitSum % 3) {
        cout << "-1\n";
    } else {
        --cnt[0];

        for (int i = 9; i >= 0; --i) {
            while (cnt[i]) {
                cout << i;
                --cnt[i];
            }
        }
        cout << 0;
    }
}