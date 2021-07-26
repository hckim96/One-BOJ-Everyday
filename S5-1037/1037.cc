#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> arr(num);

    for (auto & e: arr) {
        cin >> e;
    }

    sort(arr.begin(), arr.end());
    
    if (num % 2) {
        cout << arr[(num - 1) / 2] * arr[(num - 1) / 2] << '\n';
    } else {
        cout << arr[0] * arr[num - 1] << '\n';
    }
}