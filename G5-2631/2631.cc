#include <iostream>
#include <list>

using namespace std;

int line[200] = {0};
int N;
int lis = 0;
list<int> myList;
void LIS() {

    myList.push_back(line[0]);

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(myList.begin(), myList.end(), line[i]);
        if (it == myList.end()) {
            myList.push_back(line[i]);
        } else {
            *it = line[i];
        }
    }
    lis = myList.size();
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> line[i];
    }

    LIS();

    cout << N - lis << "\n";
}
