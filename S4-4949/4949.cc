#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    while (s != ".") {

        bool isYes = true;

        stack<char> st;
        for (auto e: s) {

            if (e == '[') {
                st.push(e);
            }

            if (e == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    isYes = false;
                    break;            
                }
            }

            if (e == '(') {
                st.push(e);
            }

            if (e == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    isYes = false;
                    break;            
                }
            }
        }

        if (!st.empty()) {
            isYes = false;
        }

        if (isYes) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }

        getline(cin, s);
    }
}