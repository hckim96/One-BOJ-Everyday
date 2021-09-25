#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 0) {
        cout << "1\n";
        return 0;
    }
    
    vector<int> v(10, 0);
    while (N) {
        ++v[N % 10];
        N /= 10;
    }
    
    int answer = 0;
    int tmp = 0;
    for (int i = 0; i < 10; ++i) {
        if (i == 6 || i == 9) {
            tmp += v[i];
        } else {
            answer = max(answer, v[i]);
        }
    }
    answer = max(answer, tmp / 2 + tmp % 2);
    cout << answer << '\n';
}