#include <iostream>
#include <vector>

using namespace std;

#define INF 2e9

void build(vector<int>& arr, vector<int>& t) {
    int N = arr.size();

    for (int i = 0; i < N; ++i) {
        t[N + i] = i;
    }

    for (int i = N - 1; i > 0; --i) {
        t[i] = (arr[t[i << 1]] < arr[t[i << 1 | 1]]) ? t[i << 1] : t[i << 1 | 1];
    }
}

// [l, r)
int query(vector<int>& arr, vector<int>& t, int l, int r) {
    int N = arr.size();
    int ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            if (arr[t[l]] < (ret ? arr[t[ret]] : INF)) {
                ret = l;
            }
            ++l;
        }

        if (r & 1) {
            --r;
            if (arr[t[r]] < (ret ? arr[t[ret]] : INF)) {
                ret = r;
            }
        }
    }

    return t[ret];
}

// max area, [l, r)
long long f(vector<int>& arr, vector<int>& t, int l, int r) {
    int minIdx = query(arr, t, l, r);

    long long ret = 1LL * (r - l) * arr[minIdx];

    if (minIdx - l) {
        ret = max(ret, f(arr, t, l, minIdx));
    }
    if (r - (minIdx + 1)) {
        ret = max(ret, f(arr, t, minIdx + 1, r));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr;
    vector<int> t;

    while (N) {
        arr.resize(N);
        t.resize(2 * N);

        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        
        build(arr, t);
        cout << f(arr, t, 0, N) << '\n';
        
        cin >> N;
    }
}
