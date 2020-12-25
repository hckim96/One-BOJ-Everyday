#include <iostream>
#include <stack>

using namespace std;

int getPriority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '(':
            return 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    
    char answer[101];
    int answerLen = 0;

    int len = str.size();

    stack<pair<char, int> > st;

    for (int i = 0; i < len; i++) {
        if ('A' <= str[i]) {
            answer[answerLen++] = str[i];
        } else if (str[i] == ')') {
            while (!st.empty() && st.top().first != '(') {
                answer[answerLen++] = st.top().first;
                st.pop();
            }
            st.pop();
        } else {
            int prirority = getPriority(str[i]);

            while (!st.empty() && st.top().first != '(' && st.top().second >= prirority) {
                answer[answerLen++] = st.top().first;
                st.pop();
            }

            st.push({str[i], prirority});
        }
    }

    while(!st.empty()) {
        answer[answerLen++] = st.top().first;
        st.pop();
    }

    answer[answerLen++] = '\0';
    cout << answer << "\n";
}