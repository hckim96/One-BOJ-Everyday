#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<pair<int, int> > st;
    long long answer = 0;

    for (int i = 0; i < N; ++i) {
        int h;
        cin >> h;
        int cnt = 1;

        while (!st.empty() && st.top().first < h) {
            answer += st.top().second;
            st.pop();
        }

        if (!st.empty()) {
            if (h == st.top().first) {
                answer += st.top().second;
                cnt = st.top().second + 1;
                st.pop();
                if (!st.empty()) {
                    ++answer;
                }
            } else {
                ++answer;
            }
        }

        st.push({h, cnt});
    }

    cout << answer << '\n';
}
