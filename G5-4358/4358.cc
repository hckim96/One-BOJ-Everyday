#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int totalCnt = 0;
    map<string, int> m;

    while (!getline(cin, s).eof()) {
        ++totalCnt;
        ++m[s];
    }
    
    cout.precision(4);
    cout << fixed;
    
    for (auto [name, cnt]: m) {
        double p = (double)cnt / totalCnt * 100;
        cout << name << ' ' << p << '\n';
    }
}