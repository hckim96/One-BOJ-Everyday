#include <iostream>
#include <vector>

using namespace std;

int main() {

    int a, b, c, d;
    cin >> a >> b >> c;
    d = a * b * c;

    vector<int> arr(10);

    while (d) {
        ++arr[d % 10];
        d /= 10;
    }
    
    for (auto e: arr) {
        cout << e << '\n';
    }
}
