#include <iostream>

using namespace std;

string calc(string& A, string& B) {
    string ret;

    auto it1 = A.rbegin();
    auto it2 = B.rbegin();

    int sum = 0;
    int carry = 0;
    
    int idx = 0;
    while (!(it1 == A.rend() && it2 == B.rend() && carry == 0)) {
        if (it1 != A.rend()) {
            sum += *it1 - '0';
            ++it1;
        }
        if (it2 != B.rend()) {
            sum += *it2 - '0';
            ++it2;
        }
        sum += carry;
        carry = sum / 10;
        sum  %= 10;
        ret = to_string(sum) + ret;
        sum = 0;
    }

    return ret;   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;

    cout << calc(A, B) << '\n';
}