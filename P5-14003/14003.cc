#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> pos(N);

    vector<int> dp;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) {
            dp.push_back(arr[i]);
            pos[i] = dp.size() - 1;
        } else {
            *it = arr[i];
            pos[i] = it - dp.begin();
        }
    }

    cout << dp.size() << '\n';

    int idx = dp.size() - 1;
    stack<int> st;

    for (int i = N - 1; i >= 0; --i) {
        if (pos[i] == idx) {
            st.push(arr[i]);
            --idx;
        }
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';
}
