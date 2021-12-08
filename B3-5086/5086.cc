#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n1, n2;
    while (cin >> n1 >> n2 && !(n1 == 0 && n2 == 0)) {
        if (n2 % n1 == 0) {
            cout << "factor\n";
        } else if (n1 % n2 == 0) {
            cout << "multiple\n";
        } else {
            cout << "neither\n";
        }
    }
}