#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int L;
    cin >> L;
    string s;
    cin >> s;

    vector<int> pi(L, 0);

    int j = 0;
    for (int i = 1; i < pi.size(); ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
            pi[i] = j;
        }
    }

    cout << L - pi[L - 1] << '\n';
}