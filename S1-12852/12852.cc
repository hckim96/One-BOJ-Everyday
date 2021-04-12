#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> visited(N + 1, 0);
    vector<int> prev(N + 1, 0);
    queue<int> q;

    q.push(N);
    visited[N] = 1;

    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        if (f == 1) {
            break;
        }

        if (f % 3 == 0 && !visited[f / 3]) {
            q.push(f / 3);
            visited[f / 3] = visited[f] + 1;
            prev[f / 3] = f;
        }

        if (f % 2 == 0 && !visited[f / 2]) {
            q.push(f / 2);
            visited[f / 2] = visited[f] + 1;
            prev[f / 2] = f;
        }

        if (!visited[f - 1]) {
            q.push(f - 1);
            visited[f - 1] = visited[f] + 1;
            prev[f - 1] = f;
        }
    }

    cout << visited[1] - 1 << '\n';
    stack<int> st;

    int num = 1;
    while (num != N) {
        st.push(num);        
        num = prev[num];
    }
    st.push(num);

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';
}
