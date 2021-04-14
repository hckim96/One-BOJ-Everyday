#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long answer = 0;

void f(vector<int>& arr, vector<int>& partSum, int idx, int end, int sum) {
    if (idx == end) {
        partSum.push_back(sum);
        return;
    }

    f(arr, partSum, idx + 1, end, sum);
    f(arr, partSum, idx + 1, end, sum + arr[idx]);
}

void f2(vector<int>& arr, vector<int>& partSum, int idx, int end, int sum, int S) {
    if (idx == end) {
        answer += upper_bound(partSum.begin(), partSum.end(), S - sum) - lower_bound(partSum.begin(), partSum.end(), S - sum);
        return;
    }

    f2(arr, partSum, idx + 1, end, sum, S);
    f2(arr, partSum, idx + 1, end, sum + arr[idx], S);
}


int main() {
    int N, S;
    cin >> N >> S;

    vector<int> arr(N);

    for (auto & e: arr) {
        cin >> e;
    }
    
    vector<int> partSum;
    int half = N / 2;
    f(arr, partSum, 0, half, 0);
    sort(partSum.begin(), partSum.end());
    f2(arr, partSum, half, N, 0, S);

    if (S == 0) {
        --answer;
    }

    cout << answer << '\n';
}
