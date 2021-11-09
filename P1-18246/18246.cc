#include <iostream>
#include <vector>

using namespace std;

class Seg2D{
public:
  int n;
  vector<vector<int>> a;
  Seg2D(int n) : n(n), a(2*n,vector<int>(2*n)){}
  void initMax(vector<vector<int>>& val){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        a[i+n][j+n] = val[i][j];
    }
    for(int i = n; i < 2*n; i++){
      for(int j = n-1; j > 0; j--) a[i][j] = max(a[i][j<<1], a[i][j<<1|1]);
    }
    for(int i = n-1; i > 0; i--){
      for(int j = 1; j < 2*n; j++){
        a[i][j] = max(a[i<<1][j], a[i<<1|1][j]);
      }
    }
  }
  void add(int x, int y, int val) {
    a[x+n][y+n] += val;
    for(int i = y+n; i > 1; i >>= 1)  a[x+n][i>>1] = a[x+n][i] + a[x+n][i^1];
    for(x = x+n; x > 1; x >>= 1){
      for(int i = y+n; i >= 1; i >>= 1){
        a[x>>1][i] = a[x][i]+a[x^1][i];        
      }
    }
  }
  int query1DMax(int x, int y1, int y2){
    int ret = -1e9;
    for(y1 += n, y2 += n+1; y1 < y2; y1 >>= 1, y2 >>= 1){
      if(y1 & 1) ret = max(ret, a[x][y1++]);
      if(y2 & 1) ret = max(ret, a[x][--y2]);
    }    
    return ret;
  }
  int queryMax(int x1, int y1, int x2, int y2) {
    int ret = -1e9;
    for(x1 += n, x2 += n+1; x1 < x2; x1 >>= 1, x2 >>= 1){
      if(x1&1) ret = max(ret, query1DMax(x1++, y1, y2));
      if(x2&1) ret = max(ret, query1DMax(--x2, y1, y2));
    }
    return ret;
  }  
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > arr(1501, vector<int> (1501, 0));

    for (int i = 0; i < N; ++i) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        ++arr[x1][y1];
        ++arr[x2][y2];
        --arr[x1][y2];
        --arr[x2][y1];
    }

    for (int x = 0; x <= 1500; ++x) {
        for (int y = 1; y <= 1500; ++y) {
            arr[x][y] += arr[x][y - 1];
        }
    }
    for (int y = 0; y <= 1500; ++y) {
        for (int x = 1; x <= 1500; ++x) {
            arr[x][y] += arr[x - 1][y];
        }
    }

    Seg2D seg(1501);
    seg.initMax(arr);
    while (M--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << seg.queryMax(x1, y1, x2 - 1, y2 - 1) << '\n';
    }
}