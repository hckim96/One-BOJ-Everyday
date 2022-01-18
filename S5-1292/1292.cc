#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int A, B;
    cin >> A >> B;

    int num = 1;
    int l = num * (num - 1) / 2 + 1;
    int r = num * (num + 1) / 2;
    int answer = 0;
    while (l <= B) {
        if (r < A) {

        } else {
            int ll = max(l, A);
            int rr = min(r, B);
            answer += num * (rr - ll + 1);
        }

        ++num;
        l = num * (num - 1) / 2 + 1;
        r = num * (num + 1) / 2;
    }

    cout << answer << '\n';
}