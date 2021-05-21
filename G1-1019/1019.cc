#include <iostream>
#include <vector>

using namespace std;

void count(vector<int>& cnt, int num, int place) {
    while (num) {
        cnt[num % 10] += place;
        num /= 10;
    }
}

void f(vector<int>& cnt, int A, int B, int place) {
    while (A != B && A % 10 != 0) {
        count(cnt, A, place);
        ++A;
    }

    while (A != B && B % 10 != 9) {
        count(cnt, B, place);
        --B;
    }

    if (A == B) {
        count(cnt, A, place);
    } else {
        for (auto & e: cnt) {
            e += (B / 10 - A / 10 + 1) * place;
        }

        f (cnt, A / 10, B / 10, place * 10);
    }
}

int main() {
    int A = 1;
    int B;
    cin >> B;

    vector<int> cnt(10, 0);

    f(cnt, A, B, 1);


    for (auto e: cnt) {
        cout << e << ' ';
    }
    cout << '\n';
}
