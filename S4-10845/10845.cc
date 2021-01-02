#include <iostream>

using namespace std;

#define N_MAX 10000

int N;

class MyQueue {
    public:
        int arr[N_MAX];
        int f = 0;
        int b = -1;

        void push(int x) {
            arr[++b] = x;
        }
        void pop() {
            f++;
        }
        int size() {
            return b - f + 1;
        }
        bool empty() {
            return (b == f - 1);
        }
        int front() {
            return arr[f];
        }
        int back() {
            return arr[b];
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    MyQueue q;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if (cmd == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (cmd == "size") {
            cout << q.size() << "\n";
        } else if (cmd == "empty") {
            cout << q.empty() << "\n";
        } else if (cmd == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (cmd == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << "\n";
            }
        }
    }
}