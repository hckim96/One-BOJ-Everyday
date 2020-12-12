#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    string star;
    for (int i = 0; i < N; i++) {
        star += '*';
        cout << star << "\n";
    }
}