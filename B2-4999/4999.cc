#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() >= s2.size()) {
        cout << "go\n";
    } else {
        cout << "no\n";
    }
}