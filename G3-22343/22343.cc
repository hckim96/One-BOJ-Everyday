#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> calc(string& s) {
    vector<int> ret((s.size() / 2) + 1, 0);
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++cnt;
        } else {
            if (s[i - 1] == '(') {
                ++ret[cnt - 1];
            }
            --cnt;
        }
    }

    int carry = 0;

    for (int i = 0; i < ret.size(); ++i) {
        ret[i] += carry;
        carry = ret[i] / 2;
        ret[i] %= 2;
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        string A;
        string B;
        cin >> A >> B;

        auto retA = calc(A);
        auto retB = calc(B);

        auto it = retA.rbegin();
        while (*it == 0) {
            ++it;
        }
        auto it2 = retB.rbegin();
        while (*it2 == 0) {
            ++it2;
        }

        if (retA.rend() - it == retB.rend() - it2) {
            while (it != retA.rend() && it2 != retB.rend() && *it == *it2) {
                ++it;
                ++it2;
            }

            if (it == retA.rend()) {
                cout << "=\n";
            } else {
                if (*it > *it2) {
                    cout << ">\n";
                } else {
                    cout << "<\n";
                }
            }
        } else {
            if (retA.rend() - it > retB.rend() - it2) {
                cout << ">\n";
            } else {
                cout << "<\n";
            }
        }
    }
}