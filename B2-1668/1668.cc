#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);

    for (auto& e: v) {
        cin >> e;
    }

    int maxx = 0;
    int l = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > maxx) {
            maxx = v[i];
            ++l;
        }
    }
    maxx = 0;
    int r = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] > maxx) {
            maxx = v[i];
            ++r;
        }
    }
    cout << l << '\n' << r << '\n';

}