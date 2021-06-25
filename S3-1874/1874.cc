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
    for (auto &e: arr) {
        cin >> e;
    }

    string answer;
    stack<int> st;

    int j = 0;
    for (int i = 1; i <= N; ++i){
        st.push(i);
        answer += "+\n";

        while (!st.empty() && st.top() == arr[j]) {
            st.pop();
            ++j;
            answer += "-\n";
        }
    }

    if (!st.empty()) {
        cout << "NO\n";
    } else {
        cout << answer;
    }
}
