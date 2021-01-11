#include <iostream>
#include <queue>

using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    priority_queue<int, vector<int>, greater<int> > pq;

    while (N--) {
        int num;
        cin >> num;

        if (num == 0) {
            if (!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            } else {
                cout << "0\n";
            }
        } else {
            pq.push(num);
        }
    }
}