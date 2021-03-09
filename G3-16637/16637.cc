#include <iostream>
#include <string>

using namespace std;

long long answer = INT64_MIN;

int calc(long long a, char op, long long b) {
    long long ret = 0;
    switch (op) {
        case '*':
            ret = a * b;
            break;
        case '+':
            ret = a + b;
            break;
        case '-':
            ret = a - b;
            break;
        
        default:
            break;
    }
    return ret;
}

void f(string& s, int idx, long long res) {
    if (idx >= s.size()) {
        answer = max(answer, res);
        return;
    }

    char prevOp = !idx ? '+' : s[idx - 1];

    f(s, idx + 2, calc(res, prevOp, s[idx] - '0'));
    if (idx + 1 != s.size()) {
        f(s, idx + 4, calc(res, prevOp, calc(s[idx] - '0', s[idx + 1], s[idx + 2] - '0')));
    }
}

int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;
    
    f(s, 0, 0);
    cout << answer << '\n';
}