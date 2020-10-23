#include <iostream>
#include <stack>

using namespace std;


// 50만, 1억
int N, H;


// {index, height}
stack<pair<int, int> > st;

int height[500000] = {0};
int receive[500000] = {0};
 
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H;
        height[i] = H;
    }

    st.push({0, height[0]});
    cout << receive[0] << " ";
    for (int i = 1; i < N; i++) {
        while (!st.empty() && st.top().second < height[i]) {
            receive[i] = 0;
            st.pop();
        }

        // == or > or empty
        if (st.empty()) {
            receive[i] = 0;
        } else {
            receive[i] = st.top().first + 1;
        }
        st.push({i, height[i]});
        cout << receive[i] << " ";

    }
    cout << "\n";

}