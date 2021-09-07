#include <iostream>
#include <vector>

using namespace std;

long long answer = 0;

void merge(vector<int>& arr, vector<int>& tmp, int l, int r) {
    int mid = l + r >> 1;
    int i = l;
    int j = mid + 1;
    int idx = l;

    long long cnt = 0;

    while (i <= mid || j <= r) {
        if (i > mid) {
            answer += mid - i + 1;
            tmp[idx++] = arr[j++];
        } else if (j > r) {
            tmp[idx++] = arr[i++];
        } else if (arr[i] <= arr[j]) {
            tmp[idx++] = arr[i++];
        } else {
            answer += mid - i + 1;
            tmp[idx++] = arr[j++];
        }
    }

    for (int k = l; k <= r; ++k) {
        arr[k] = tmp[k];
    }
}

void mergeSort(vector<int>& arr, vector<int>& tmp, int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = l + r >> 1;
    mergeSort(arr, tmp, l, mid);
    mergeSort(arr, tmp, mid + 1, r);
    merge(arr, tmp, l, r);    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> arr(N);
    vector<int> tmp(N);

    for (auto& e: arr) {
        cin >> e;
    }

    mergeSort(arr, tmp, 0, N - 1);

    cout << answer << '\n';
}