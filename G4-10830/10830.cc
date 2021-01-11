#include <iostream>
#include <vector>

using namespace std;

long long N, B;
vector<vector<long long> > A;

vector<vector<long long> > matMul(vector<vector<long long> > v1, vector<vector<long long> > v2) {
    vector<vector<long long> > v3;

    for (int i = 0; i < N; i++) {
        v3.push_back({});
        for (int j = 0; j < N; j++) {
            long long num = 0;
            for (int k = 0; k < N; k++) {
                num += v1[i][k] * v2[k][j];
            }
            num = num % 1000;
            v3[i].push_back(num);
        }
    }
    return v3;

}

vector<vector<long long> > f(long long n) {

    vector<vector<long long> > answer;
    for (int i = 0; i < N; i++) {
        answer.push_back({});
        for (int j = 0; j < N; j++) {
            if (i == j) {
                answer[i].push_back(1);
            } else {
                answer[i].push_back(0);
            }
        }
    }
    while (n > 0) {
        if (n % 2 == 0) {
            n /= 2;
            A = matMul(A, A);
        } else {
            n--;
            answer = matMul(A, answer);
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        A.push_back({});
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            A[i].push_back(num);
        }
    }

    vector<vector<long long> > a = f(B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    
}