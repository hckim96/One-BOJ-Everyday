#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 50
#define M_MAX 50

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<int> peopleOfParty[M];
    vector<int> partyOfPerson[N + 1];
    vector<int> canLie(M, 1);

    int knowNum;
    cin >> knowNum;

    queue<int> q;
    for (int i = 0; i < knowNum; i++) {
        int num;
        cin >> num;
        q.push(num);
    }


    for (int i = 0; i < M; i++) {
        int peopleNum;
        cin >> peopleNum;
        for (int j = 0; j < peopleNum; j++) {
            int num;
            cin >> num;
            partyOfPerson[num].push_back(i);
            peopleOfParty[i].push_back(num);
        }
    }

    int visited[N_MAX + 1] = {0};
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        visited[front] = 1;

        for (auto party: partyOfPerson[front]) {
            canLie[party] = 0;
            for (auto person: peopleOfParty[party]) {
                if (visited[person]) {
                    continue;
                }

                q.push(person);
            }
        }
    }

    int answer = 0;
    for (auto e: canLie) {
        if (e) {
            answer++;
        }
    }

    cout << answer << "\n";
}