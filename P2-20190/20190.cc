#include <iostream>
#include <vector>

using namespace std;

void merge(vector<pair<int, int> >& v, vector<pair<int, int> >& tmp, vector<int>& inversionCnt, int l, int r) {
    int mid = l + r >> 1;
    
    int idx = l;
    int i = l;
    int j = mid + 1;

    while (i <= mid && j <= r) {
        if (v[i] <= v[j]) {
            inversionCnt[v[i].second] += j - mid - 1;
            tmp[idx] = v[i];
            ++idx, ++i;

        } else {
            inversionCnt[v[j].second] += mid - i + 1;
            tmp[idx] = v[j];
            ++idx, ++j;
        }
    }

    while (i <= mid) {
        inversionCnt[v[i].second] += j - mid - 1;
        tmp[idx] = v[i];
        ++idx, ++i;
    }
    while (j <= r) {
        inversionCnt[v[j].second] += mid - i + 1;
        tmp[idx] = v[j];
        ++idx, ++j;
    }
    for (int k = l; k <= r; ++k) {
        v[k] = tmp[k];
    }
}

void mergeSort(vector<pair<int, int> >& v, vector<pair<int, int> >& tmp, vector<int>& inversionCnt, int l, int r) {
    if (l < r) {
        int mid = l + r >> 1;
        mergeSort(v, tmp, inversionCnt, l, mid);
        mergeSort(v, tmp, inversionCnt, mid + 1, r);
        merge(v, tmp, inversionCnt, l, r);
    }

}

int LEAFSIZE;
vector<int> t;
vector<int> lazy;
const int INF = 1e8;

void propagate(int node, int ns, int ne) {
    if (lazy[node] != 0) {
        if (node < LEAFSIZE) {
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }

        t[node] += lazy[node];
        lazy[node] = 0;
    }
}
void add(int s, int e, int v, int node, int ns, int ne) {
    propagate(node, ns, ne);
    if (e <= ns || ne <= s) return;
    if (s <= ns && ne <= e) {
        lazy[node] += v;
        propagate(node, ns, ne);
        return;
    }
    int mid = ns + ne >> 1;
    add(s, e, v, node << 1, ns, mid);
    add(s, e, v, node << 1 | 1, mid, ne);
    t[node] = min(t[node << 1], t[node << 1 | 1]);
}
int query(int s, int e, int node, int ns, int ne) {
    propagate(node, ns, ne);
    if (e <= ns || ne <= s) return INF;
    if (s <= ns && ne <= e) return t[node];
    int mid = ns + ne >> 1;
    return min(query(s, e, node << 1, ns, mid), query(s, e, node << 1 | 1, mid, ne));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<pair<int, int> > tmp(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        tmp[i] = {A[i], i};
    }

    vector<pair<int, int> > ttmp(A.size());
    vector<int> inversionCnt(A.size(), 0);

    mergeSort(tmp, ttmp, inversionCnt, 0, N - 1);

    long long inversionSum = 0;
    for (auto e: inversionCnt) {
        inversionSum += e;
    }

    int base = 1;
    while (base < 1000001) {
        base <<= 1;
    }
    LEAFSIZE = base;
    t.resize(2 * LEAFSIZE, 0);
    lazy.resize(2 * LEAFSIZE, 0);


    cout << (inversionSum) / 2 - inversionCnt[0] << ' ';
    for (int i = 1; i < N; ++i) {
        add(A[i] + 1, LEAFSIZE, 1, 1, 0, LEAFSIZE);
    }

    for (int i = 1; i < N; ++i) {
        add(0, A[i - 1], 1, 1, 0, LEAFSIZE);
        add(A[i] + 1, LEAFSIZE, -1, 1, 0, LEAFSIZE);
        int min_ = query(0, LEAFSIZE, 1, 0, LEAFSIZE);
        cout << inversionSum / 2 - inversionCnt[i] + query(0, LEAFSIZE, 1, 0, LEAFSIZE) << ' ';
    }
    cout << '\n';
}