#include <iostream>
#include <vector>

using namespace std;

// [l, r)
int query(vector<int>& arr, vector<int>& t, int l, int r) {
    int N = t.size() / 2;
    int ret = l;

    for (l += N, r += N; l < r; l >>=1, r >>= 1) {
        if (l & 1) {
            if (arr[ret] > arr[t[l]]) {
                ret = t[l];
            }
            ++l;
        }
        if (r & 1) {
            --r;
            if (arr[ret] > arr[t[r]]) {
                ret = t[r];
            }
        }
    }

    return ret;
}

// [l, r)
int f(vector<int>& arr, vector<int>& t, int l, int r) {

    int minHeightIdx = query(arr, t, l, r);

    int ret = arr[minHeightIdx] * (r - l);

    if (minHeightIdx - l) {
        ret = max(ret, f(arr, t, l, minHeightIdx));
    }

    if (r - (minHeightIdx + 1)) {
        ret = max(ret, f(arr, t, minHeightIdx + 1, r));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> t(2 * N, -1);

    for (auto& e: arr) {
        cin >> e;
    }

    for (int i = 0; i < N; ++i) {
        t[N + i] = i;
    }
    for (int i = N - 1; i > 0; --i) {
        t[i] = arr[t[i << 1]] < arr[t[i << 1 | 1]] ? t[i << 1] : t[i << 1 | 1];
    }


    cout << f(arr, t, 0, N) << '\n';
}