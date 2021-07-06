#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;

    string s = to_string(N);
    sort(s.begin(), s.end(), greater<int>());

    cout << s << '\n';
}