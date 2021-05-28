#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> maxSegmentTree(2 * N, 0);
    vector<int> minSegmentTree(2 * N,  2e9);

    for (int i = 0; i < N; ++i) {
        cin >> maxSegmentTree[N + i];
        minSegmentTree[N + i] = maxSegmentTree[N + i];
    }

    for (int i = N - 1; i >= 1; --i) {
        minSegmentTree[i] = min(minSegmentTree[i << 1], minSegmentTree[i << 1 | 1]);
        maxSegmentTree[i] = max(maxSegmentTree[i << 1], maxSegmentTree[i << 1 | 1]);
    }


    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;

        int min_ = 2e9;
        int max_ = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                max_ = max(max_, maxSegmentTree[l]);
                min_ = min(min_, minSegmentTree[l]);
                ++l;
            }
            if (r & 1) {
                --r;
                max_ = max(max_, maxSegmentTree[r]);
                min_ = min(min_, minSegmentTree[r]);
            }
        }

        cout << min_ << ' ' << max_ << '\n';
    }
}
