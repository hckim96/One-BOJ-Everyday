#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (maxHeap.empty()) {
            maxHeap.push(num);
            cout << num << '\n';
            continue;
        }

        if (maxHeap.size() == minHeap.size()) {
            if (minHeap.top() >= num) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } else {
            if (maxHeap.top() <= num) {
                minHeap.push(num);
            } else {
                maxHeap.push(num);
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }

        cout << maxHeap.top() << '\n';
    }
}