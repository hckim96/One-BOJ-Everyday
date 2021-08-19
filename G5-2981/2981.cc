#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (auto& e:arr) {
        cin >> e;
    }

    sort(arr.begin(), arr.end());

    int _gcd = arr[1] - arr[0];

    for (int i = 1; i < N - 1; ++i) {
        _gcd = gcd(_gcd, arr[i + 1] - arr[i]);    
    }

    vector<int> answer;

    if (_gcd != 1) {
        answer.push_back(_gcd);
    }

    for (int i = 2; i * i <= _gcd; ++i) {
        if (_gcd % i == 0) {
            answer.push_back(i);
            if (i * i != _gcd) {
                answer.push_back(_gcd / i);
            }
        }
    }

    sort(answer.begin(), answer.end());

    for (auto e: answer) {
        cout << e << ' ';
    }
    cout << '\n';
}