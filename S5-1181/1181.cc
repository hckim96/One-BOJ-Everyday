#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N_MAX 20000

int N;
string arr[N_MAX];

// arg 순서 유지될지 return
bool cmp(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    } else {
        return s1.compare(s2) < 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, cmp);

    string prev;
    for (int i = 0; i < N; i++) {
        if (prev != arr[i]) {
            cout << arr[i] << "\n";
        }
        prev = arr[i];
    }

}