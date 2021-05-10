#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<vector<int> > operator*(vector<vector<int> > a, vector<vector<int> > b) {
    vector<vector<int> > tmp(a.size(), vector<int> (b[0].size()));

    for (int r = 0; r < a.size(); ++r) {
        for (int c = 0; c < b[0].size(); ++c) {
            long long tmp2 = 0;
            for (int i = 0; i < a[0].size(); ++i) {
                tmp2 += 1LL * a[r][i] * b[i][c];
                tmp2 %= MOD;
            }
            tmp[r][c] = tmp2;
        }
    }

    return tmp;
}

vector<vector<int> > f(vector<vector<int> > A, int D) {
    if (D == 1) {
        return A;
    }
    
    if (D % 2 == 0) {
        auto tmp = f(A, D / 2);
        return tmp * tmp;
    } else {
        return A * f(A, D - 1);        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D;
    cin >> D;

    vector<vector<int> > A = {
        {0, 1, 1, 0, 0, 0, 0, 0}, 
        {1, 0, 1, 1, 0, 0, 0, 0}, 
        {1, 1, 0, 1, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 1, 1, 0, 0}, 
        {0, 0, 1, 1, 0, 1, 0, 1}, 
        {0, 0, 0, 1, 1, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 1, 0, 1}, 
        {0, 0, 0, 0, 1, 0, 1, 0}};

    A = f(A, D);
    cout << A[0][0] << '\n';
}