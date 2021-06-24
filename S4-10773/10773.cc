#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    stack<int> st;
    
    while (K--) {
        int num;
        cin >> num;

        if (num) {
            st.push(num);
        } else {
            st.pop();
        }
    }

    int answer = 0;
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    cout << answer << '\n';
}