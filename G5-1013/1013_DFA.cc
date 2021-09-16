#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v = {
    {1, 3},
    {9, 2},
    {1, 3},
    {4, 9},
    {5, 9},
    {5, 6},
    {1, 7},
    {8, 7},
    {5, 2},
    {9, 9}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        int state = 0;
        for (auto e: s) {
            state = v[state][e - '0'];
        }

        if (state == 2 || state == 6 || state == 7) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
