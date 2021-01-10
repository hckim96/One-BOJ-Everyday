#include <iostream>
#include <queue>

using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    int answer = 0;
    while (pq.size() > 1) {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();

        answer += n1 + n2;
        pq.push(n1 + n2);
    }

    cout << answer << "\n";
}