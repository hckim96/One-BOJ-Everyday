#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> v(N);
    for (auto& e: v) cin >> e;

    for (int i = 1; i < v.size(); ++i) {
        int gcd_ = gcd(v[0], v[i]);
        cout << v[0] / gcd_ << '/' << v[i] / gcd_ << '\n'; 
    }
}