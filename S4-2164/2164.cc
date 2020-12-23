#include <iostream>
#include <queue>

using namespace std;

int N;
int main() {
    cin >> N;

    queue<int> q;
        
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }

    bool moveBack = false;
    int size = q.size();

    while (size > 1) {
        if (moveBack) {
            q.push(q.front());
            size++;
        }
        q.pop();
        moveBack = !moveBack;
        size--;
    }
    
    cout << q.front() << "\n";
}