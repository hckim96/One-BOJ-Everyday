#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    
    vector<int> crane(N);
    for (auto& e: crane) {
        cin >> e;
    }

    int M;
    cin >> M;
    vector<int> box(M);
    for (auto& e: box) {
        cin >> e;
    }

    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end(), greater<int>());

    if (crane.back() < box.front()) {
        cout << "-1\n";
        return 0;
    }

    int time = 0;
    while (!box.empty() && ++time) {
        auto it = box.begin();
        for (int i = crane.size() - 1; i >= 0; --i) {
            while (it != box.end() && *it > crane[i]) {
                ++it;
            }
            if (it == box.end()) break;
            box.erase(it);
        }
    }

    cout << time << '\n';
}