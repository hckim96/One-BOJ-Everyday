#include <iostream>
#include <vector>

using namespace std;

void build(vector<int>& segmentTree, vector<int>& arr, int idx, int l, int r, bool isMaxSegmentTree) {
    if (l == r) {
        segmentTree[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(segmentTree, arr, 2 * idx, l, mid, isMaxSegmentTree);
    build(segmentTree, arr, 2 * idx + 1, mid + 1, r, isMaxSegmentTree);

    if (isMaxSegmentTree) {
        segmentTree[idx] = max(segmentTree[2 * idx], segmentTree[2 * idx + 1]);
    } else {
        segmentTree[idx] = min(segmentTree[2 * idx], segmentTree[2 * idx + 1]);
    }
}

int query(vector<int>& segmentTree, int idx, int tl, int tr, int l, int r, bool isMaxSegmentTree) {
    if (r < tl || l > tr) {
        if (isMaxSegmentTree) {
            return 0;
        } else {
            return 2e9;
        }
    }

    if (l <= tl && tr <= r) {
        return segmentTree[idx];
    }

    int tm = (tl + tr) / 2;

    if (isMaxSegmentTree) {
        return max(query(segmentTree, 2 * idx, tl, tm, l, r, isMaxSegmentTree), query(segmentTree, 2 * idx + 1, tm + 1, tr, l, r, isMaxSegmentTree));
    } else {
        return min(query(segmentTree, 2 * idx, tl, tm, l, r, isMaxSegmentTree), query(segmentTree, 2 * idx + 1, tm + 1, tr, l, r, isMaxSegmentTree));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> arr(N + 1, 0);
    vector<int> maxSegmentTree(4 * N + 1, 0);
    vector<int> minSegmentTree(4 * N + 1,  2e9);

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    build(maxSegmentTree, arr, 1, 1, N, true);
    build(minSegmentTree, arr, 1, 1, N, false);

    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        cout << query(minSegmentTree, 1, 1, N, l, r, false) << ' ' << query(maxSegmentTree, 1, 1, N, l, r, true) << '\n';
    }
}
