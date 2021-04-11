#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> F(1e6 + 1, 0);

    for (auto & e: A) {
        cin >> e;
        ++F[e];
    }

    vector<int> NGF(N);

    stack<int> st;

    for (int i = N - 1; i >= 0; --i) {
        while (!st.empty() && F[st.top()] <= F[A[i]]) {
            st.pop();
        }

        int ngf = -1;
        if (!st.empty()) {
            ngf = st.top();
        }
        NGF[i] = ngf;
        st.push(A[i]);
    }

    for (int i = 0; i < N; ++i) {
        cout << NGF[i] << ' ';
    }
    cout << '\n';
}
