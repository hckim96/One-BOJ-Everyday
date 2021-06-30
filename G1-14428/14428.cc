#include <iostream>
#include <vector>

using namespace std;

void modify(vector<int>& arr, vector<int>& t, int i, int v) {
    arr[i] = v;

    int tIdx = arr.size() + i;

    while (tIdx > 1) {
        int idx1 = t[tIdx];
        int idx2 = t[tIdx ^ 1];
        int retIdx;
        if (arr[idx1] < arr[idx2]) {
            retIdx = idx1;
        } else if (arr[idx1] == arr[idx2]) {
            retIdx = min(idx1, idx2);
        } else {
            retIdx = idx2;
        }
        t[tIdx >> 1] = retIdx;
        tIdx >>= 1;  
    }
}

int query(vector<int>& arr, vector<int>& t, int i, int j) {
    int N = t.size() / 2;

    int retIdx = t[N + i];
    int l, r;
    for (l = N + i, r = N + j + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            int idx = t[l];
            if (arr[idx] < arr[retIdx]) {
                retIdx = idx;
            } else if (arr[idx] == arr[retIdx]) {
                retIdx = min(retIdx, idx);
            } else {
                retIdx = retIdx;
            }
            ++l;
        }

        if (r & 1) {
            --r;
            int idx = t[r];
            if (arr[idx] < arr[retIdx]) {
                retIdx = idx;
            } else if (arr[idx] == arr[retIdx]) {
                retIdx = min(retIdx, idx);
            } else {
                retIdx = retIdx;
            }
        }
    }
    
    return retIdx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> t(2 * N, -1);
    vector<int> arr(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        t[N + i] = i;
    }

    for (int i = N - 1; i > 0; --i) {
        int idx1 = t[i << 1];
        int idx2 = t[i << 1 | 1];
        int retIdx;
        if (arr[idx1] < arr[idx2]) {
            retIdx = idx1;
        } else if (arr[idx1] == arr[idx2]) {
            retIdx = min(idx1, idx2);
        } else {
            retIdx = idx2;
        }
        t[i] = retIdx;
    }

    int M;
    cin >> M;
    while (M--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        
        if (n1 == 1) {
            modify(arr, t, n2 - 1, n3);
        } else {
            cout << query(arr, t, n2 - 1, n3 - 1) + 1 << '\n';
        }
    }
}
