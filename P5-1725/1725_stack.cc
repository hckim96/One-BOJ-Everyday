#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (auto& e: arr) {
        cin >> e;
    }

    int answer = 0;
    stack<int> st;

    for (int i = 0; i < arr.size(); ++i) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int right = i;
            int height = arr[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            answer = max(answer, (right - left - 1) * height);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int right = N;
        int height = arr[st.top()];
        st.pop();
        int left = st.empty() ? -1 : st.top();
        answer = max(answer, (right - left - 1) * height);
    }

    cout << answer << '\n';
}