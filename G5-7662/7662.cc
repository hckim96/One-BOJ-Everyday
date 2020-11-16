#include <iostream>
#include <set>

using namespace std;

int T, K;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> K;
        multiset<int> myMultiset;

        for (int j = 0; j < K; j++) {
            char operation;
            int number;
            cin >> operation >> number;

            if (operation == 'I') {
                myMultiset.insert(number);
            } else if (operation == 'D') {
                if (!myMultiset.empty()) {
                    if (number == 1) {
                        myMultiset.erase(--myMultiset.end());
                    } else if (number == -1) {
                        myMultiset.erase(myMultiset.begin());
                    }
                }

            }

        }

        if (!myMultiset.empty()) {
            cout << *(--myMultiset.end()) << " "<< *myMultiset.begin() << "\n";
        } else {
            cout << "EMPTY\n";
        }
    }
}