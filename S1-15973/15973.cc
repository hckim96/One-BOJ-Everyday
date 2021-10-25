#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int x1, y1, x2, y2;
    int xx1, yy1, xx2, yy2;

    cin >> x1 >> y1 >> x2 >> y2 >> xx1 >> yy1 >> xx2 >> yy2;

    if (xx2 < x1 || x2 < xx1 || yy2 < y1 || y2 < yy1) {
        cout << "NULL\n";
    } else if (xx2 == x1 || x2 == xx1 || yy2 == y1 || y2 == yy1) {
        if ((x1 == xx2 && (y1 == yy2 || y2 == yy1)) || (x2 == xx1 && (y1 == yy2 || y2 == yy1))) {
            cout << "POINT\n";
        } else {
            cout << "LINE\n";
        }
    } else {
        cout << "FACE\n";
    }
}