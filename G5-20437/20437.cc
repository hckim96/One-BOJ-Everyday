#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        string w;
        int k;
        cin >> w >> k;

        vector<vector<int> > p(26);

        for (int i = 0; i < w.size(); ++i) {
            p[w[i] - 'a'].push_back(i);
        }

        int p1 = 0;
        int p2 = -1;
        
        int p3 = 0;
        int p4 = w.size();
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j + k - 1 < p[i].size(); ++j) {
                if (p2 - p1 < p[i][j + k - 1] - p[i][j]) {
                    p1 = p[i][j];
                    p2 = p[i][j + k - 1];
                }

                if (p4 - p3 > p[i][j + k - 1] - p[i][j]) {
                    p3 = p[i][j];
                    p4 = p[i][j + k - 1];
                }
            }
        }

        if (p2 == -1) {
            cout << "-1\n";
        } else {
            cout << p4 - p3 + 1 << ' ' << p2 - p1 + 1 << '\n';
        }
    }
}