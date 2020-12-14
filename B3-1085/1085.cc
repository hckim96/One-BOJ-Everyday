#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int arr[4] = {x, y, abs(x - w), abs(y - h)};

    int answer = 2000;
    for (int i = 0; i < 4; i++) {
        answer = min(answer, arr[i]);
    }

    cout << answer << "\n";
}