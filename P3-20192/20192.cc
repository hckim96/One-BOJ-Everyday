#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    int cnt = 0;
    bool ascending = true;
    int prev = -1;
    bool flag = false;
    while (N--) {
        int num;
        cin >> num;
        
        if (ascending && prev > num) {
            ascending = !ascending;
            ++cnt;
            flag = true;
        } else if (!ascending && prev < num) {
            ascending = !ascending;
        }
        prev = num;
    }
    if (ascending) ++cnt;

    if (!flag) {
        cout << "0\n";
    } else {
        cout << (int)log2(cnt) + (log2(cnt) - (int)log2(cnt) > 0) + 1 << '\n';
    }
}