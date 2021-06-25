#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    int maxHeight = 0;
    for (auto &e: arr) {
        cin >> e;
        maxHeight = max(maxHeight, e);
    }


    int l = 0;
    int r = maxHeight;

    while (l + 1 < r) {

        int mid = (l + r) / 2;
        long long sum = 0;

        for (auto e: arr) {
            sum += (e > mid ? e - mid : 0);
        }

        if (sum < M) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << l << '\n';
}
