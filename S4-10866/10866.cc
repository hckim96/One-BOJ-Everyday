#include <iostream>

using namespace std;

#define N_MAX 10000

int N;

class MyDeque {
    public:
        int arr[2 * N_MAX];
        int f = N_MAX;
        int b = f - 1;

        void push_front(int x) {
            arr[--f] = x;
        }
        void push_back(int x) {
            arr[++b] = x;
        }
        void pop_front() {
            f++;
        }
        void pop_back() {
            b--;
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

    MyDeque dq;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int num;
            cin >> num;
            dq.push_front(num);
        } else if (cmd == "push_back") {
            int num;
            cin >> num;
            dq.push_back(num);
        } else if (cmd == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (cmd == "size") {
            cout << dq.size() << "\n";
        } else if (cmd == "empty") {
            cout << dq.empty() << "\n";
        } else if (cmd == "front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << "\n";
            }
        } else if (cmd == "back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << "\n";
            }
        }
    }
}