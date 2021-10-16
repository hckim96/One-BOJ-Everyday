#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string S, T;
    cin >> S >> T;

    vector<vector<int> > v(26);

    for (int i = 0; i < T.size(); ++i) {
        v[T[i] - 'a'].push_back(i);
    }
    
    int it = T.size() - 1;
    int answer = 0;
    for (auto e: S) {
        if (v[e - 'a'].empty()) {
            answer = -1;
            break;
        }

        auto nit = upper_bound(v[e - 'a'].begin(), v[e - 'a'].end(), it);
        if (nit == v[e - 'a'].end()) {
            it = v[e - 'a'][0];
            ++answer;
        } else {
            it = *nit;
        }
    }

    cout << answer << '\n';
}