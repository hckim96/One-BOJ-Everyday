#include <iostream>

using namespace std;

#define N_MAX 100000
int N;

class MyStack {
    public:
        int arr[N_MAX];
        int s = 0;

        void push(int x) {
            arr[s++] = x;
        }

        void pop() {
            s--;
        }

        int size() {
            return s;
        }

        bool empty() {
            return (s == 0);
        }


        int top() {
            return arr[s - 1];
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    MyStack s;
    for (int i = 0; i < N; i++) {
        string cmd;

        cin >> cmd;
        
        if (cmd == "push") {
            int num;
            cin >> num;
            s.push(num);
        } else if (cmd == "pop") {
            if (!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            } else {
                cout << "-1\n";
            }
        } else if (cmd == "size") {
            cout << s.size() << "\n";

        } else if (cmd == "empty") {
            cout << s.empty() << "\n";

        } else if (cmd == "top") {
            if (!s.empty()) {
                cout << s.top() << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}