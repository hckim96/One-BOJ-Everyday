#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(42, 0);

    for (int i = 0; i < 10; ++i) {
        int num;
        cin >> num;

        ++v[num % 42];
    }

    int answer = 0;
    for (auto e: v) {
        if (e) {
            ++answer;
        }
    }

    cout << answer << '\n';
}
