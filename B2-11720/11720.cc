#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string tmp;
    int N;
    int sum = 0;
    cin >> N;
    cin >> tmp;

    for (auto c : tmp) {
        sum += c - '0';
    }
    
    cout << sum << "\n";
}