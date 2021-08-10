#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    queue<int> q;
    q.push(A);

    int cnt = 0;
    while (!q.empty()) {
        ++cnt;
        int qSize = q.size();
        while (qSize--) {
            int f = q.front();
            q.pop();

            if (f == B) {
                cout << cnt << '\n';
                return 0;
            }

            if (f <= B / 2) {
                q.push(2 * f);
            }
            if (f <= (B - 1) / 10) {
                q.push(10 * f + 1);
            }
        }
    }

    cout << "-1\n";
}