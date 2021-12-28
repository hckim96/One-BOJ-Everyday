#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int K;
    cin >> K;
    string s;
    cin >> s;

    int i = 0;
    string answer = "";

    while (i < s.size()) {
        answer += s[i];
        i += K;
    }

    cout << answer << '\n';
}