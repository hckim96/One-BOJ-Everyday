#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int LEAFSIZE;

// [l, r)
void propagate(vector<int>& t, vector<int>& lazy, int n, int ns, int ne) {
    if (lazy[n]) {
        if (n < LEAFSIZE) {
            lazy[n << 1] += lazy[n];
            lazy[n << 1 | 1] += lazy[n];
        }
        t[n] += lazy[n];
        lazy[n] = 0;
    }
}

void add(vector<int>& t, vector<int>& lazy, int s, int e, int v, int n, int ns, int ne) {
    propagate(t, lazy, n, ns, ne);
    if (e <= ns || ne <= s) return;
    if (s <= ns && ne <= e) {
        lazy[n] += v;
        propagate(t, lazy, n, ns, ne);
        return;
    }

    int mid = ns + ne >> 1;
    add(t, lazy, s, e, v, n << 1, ns, mid);
    add(t, lazy, s, e, v, n << 1 | 1, mid, ne);
    t[n] = max(t[n << 1], t[n << 1 | 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int base = 1;

    while (base < int(1e6 + 1)) {
        base <<= 1;
    }
    LEAFSIZE = base;

    int N;
    cin >> N;

    vector<int> t1(2 * LEAFSIZE, 0);
    vector<int> lazy1(2 * LEAFSIZE, 0);
    vector<int> t2(2 * LEAFSIZE, 0);
    vector<int> lazy2(2 * LEAFSIZE, 0);
    int prevX, prevY;   
    int firstX, firstY;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        x += 5e5;
        y += 5e5;
        if (i == 0) {
            firstX = x;
            firstY = y;
            prevX = x;
            prevY = y;
            continue;
        }

        if (y == prevY) {
            int l = min(x, prevX);
            int r = max(x, prevX);
            if (l < r) add(t2, lazy2, l, r, 1, 1, 0, LEAFSIZE);
        } else {
            int l = min(y, prevY);
            int r = max(y, prevY);
            if (l < r) add(t1, lazy1, l, r, 1, 1, 0, LEAFSIZE);
        }

        prevX = x;
        prevY = y;
    }

    if (prevY == firstY) {
        int l = min(prevX, firstX);
        int r = max(prevX, firstX);
        if (l < r) add(t2, lazy2, l, r, 1, 1, 0, LEAFSIZE);
    } else {
        int l = min(firstY, prevY);
        int r = max(firstY, prevY);
        if (l < r) add(t1, lazy1, l, r, 1, 1, 0, LEAFSIZE);
    }

    cout << max(t1[1], t2[1]) << '\n';
}