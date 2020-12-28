#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N_MAX 100000

bool cmp(pair<int, string> p1, pair<int, string> p2) {
    
    return p1.first < p2.first;
}

pair<int, string> member[N_MAX];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        member[i].first = age;
        member[i].second = name;
    }

    stable_sort(member, member + N, cmp);

    for (int i = 0; i < N; i++) {
        cout << member[i].first << ' ' << member[i].second << '\n';
    }
}