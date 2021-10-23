#include <iostream>
#include <vector>

using namespace std;

vector<int> v = {60, 10, -10, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> ret(5, 0);

        for (int i = 0; i < v.size(); ++i) {
            if (v[i] < 0) continue;
            ret[i] += N / v[i];
            N %= v[i];
        }
        
        if (ret[3] >= 6) {
            ++ret[1];
            ret[4] = 10 - ret[3];
            ret[3] = 0;
        }

        if (ret[1] >= 4) {
            ++ret[0];
            ret[2] = 6 - ret[1];
            ret[1] = 0;
        }

        if (ret[3] >= 5 && ret[2] > 0) {
            --ret[2];
            ret[4] += 10 - ret[3];
            ret[3] = 0;
        }
        
        for (auto e: ret) {
            cout << e << ' ';
        }
        cout << '\n';
    }
}