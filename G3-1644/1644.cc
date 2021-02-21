#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<bool> isPrime(N + 1, true);
    int sqrtN = sqrt(N);
    for (int i = 2; i <= sqrtN; ++i) {

        if (!isPrime[i]) {
            continue;
        }

        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }

    vector<int> prime;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }

    if (prime.size() == 0) {
        cout << "0\n";
        return 0;
    }
    
    int answer = 0;

    int start = 0;
    int end = 1;
    int partSum = prime[0];
    while (start < end && end <= prime.size()) {
        if (partSum < N) {
            if (end == prime.size()) {
                break;
            }
            partSum += prime[end++];
        } else if (partSum == N) {
            answer++;
            partSum -= prime[start++];
        } else {
            partSum -= prime[start++];
        }
    }

    cout << answer << '\n';


}