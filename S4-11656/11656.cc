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

    string tmp;
    vector<string> ttmp;

    for (int i = s.size() - 1; i >= 0; --i) {
        tmp = s[i] + tmp;
        ttmp.push_back(tmp);
    }

    sort(all(ttmp));

    for (auto e: ttmp) {
        cout << e << '\n';
    }
    
}