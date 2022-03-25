#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;
    int min_ = min({a, b, c});
    if (a + b + c >= 100) {
        cout << "OK";
    } else if (min_ == a) {
        cout << "Soongsil";
    } else if (min_ == b) {
        cout << "Korea";
    } else {
        cout << "Hanyang";
    }
}