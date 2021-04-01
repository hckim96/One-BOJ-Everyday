#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string s;
    cin >> s;
    vector<pair<int, char> > cnt(26, {0, 'A'});
    for (auto & e: s) {
        e = toupper(e);
        ++cnt[e - 'A'].first;
        cnt[e - 'A'].second = e;
    }

    sort(cnt.begin(), cnt.end(), greater<pair<int, char> > ());

    if (cnt[0].first == cnt[1].first) {
        cout << "?\n";
    } else {
        cout << cnt[0].second << '\n';
    }
}