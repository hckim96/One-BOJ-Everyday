#include <iostream>
#include <stack>

using namespace std;

#define N_MAX 1000000

int NGE[N_MAX] = {0};
int arr[N_MAX] = {0};
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<pair<int, int> > st;

    for (int i = 0; i < N; i++) {
        while (!st.empty() && st.top().second < arr[i]) {
            NGE[st.top().first] = arr[i];
            st.pop();
        }
        st.push({i, arr[i]});
    }
    
    while (!st.empty()) {
        NGE[st.top().first] = -1;
        st.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << NGE[i] << " ";
    }
    cout << "\n";
}
