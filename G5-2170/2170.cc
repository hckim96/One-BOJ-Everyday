#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 1000000
pair<int, int> line[N_MAX];

int N;
int main() {
    // cout/cin printf/scanf 혼용시 순서 보장 못할 수 있음
    ios_base::sync_with_stdio(false);

    // cin 앞에 있는 cout 이 flush 되기 전에 cin 이 막을 수 있음
    cin.tie(NULL);

    cin >> N;

    
    for (int i = 0; i < N; i++) {
        int start, end;

        cin >> start >> end;

        line[i] = {start, end};
    }


    sort(line, line + N);

    int sectionStart = line[0].first;
    int sectionEnd = line[0].second;
    int sum = sectionEnd - sectionStart;


    for (int i = 1; i < N; i++) {
        if (line[i].first <= sectionEnd) {
            if (line[i].second <= sectionEnd) {
                continue;
            } else {
                sum += line[i].second - sectionEnd;
                sectionEnd = line[i].second;
            }
        } else {
            sectionStart = line[i].first;
            sectionEnd = line[i].second;
            sum += sectionEnd - sectionStart;
        }
    }

    cout << sum << "\n";
}