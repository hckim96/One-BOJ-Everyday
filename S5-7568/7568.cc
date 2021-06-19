#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > arr(N);

    for (auto &[f, s]: arr) {
        cin >> f >> s;
    }

    for (int i = 0; i < N; ++i) {
        int place = 1;
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                continue;
            }

            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
                ++place;
            }
        }
        cout << place << '\n';
    }
}