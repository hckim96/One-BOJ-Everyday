#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int tmp = N;
    int cnt = 0;
    
    do {
        ++cnt;
        int n1 = tmp / 10;
        int n2 = tmp % 10;
        tmp = n2 * 10 + (n1 + n2) % 10;
    } while (tmp != N);


    cout << cnt << '\n';
}