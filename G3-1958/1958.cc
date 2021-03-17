#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<vector<vector<int> > > LCS(s1.size() + 1, vector<vector<int> > (s2.size() + 1, vector<int> (s3.size() + 1, 0)));

    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            for (int k = 1; k <= s3.size(); ++k) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;
                } else {
                    LCS[i][j][k] = max(LCS[i - 1][j][k], max(LCS[i][j - 1][k], LCS[i][j][k - 1]));
                }
            }
        }
    }

    cout << LCS[s1.size()][s2.size()][s3.size()] << '\n';
}