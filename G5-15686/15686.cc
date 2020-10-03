#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int** map;
int answer = INT32_MAX;
vector<pair<int, int> > chicken, house;
bool isSelectedChicken[13];
void dfs(int selectedChickenNum, int chickenIndex) {
    if (selectedChickenNum == M) {
        // selected m chicken, calculate sum of distances
        int sumOfDistances = 0;
        for (int i = 0; i < house.size(); i++) {
            int minDistance = 2 * N;
            for (int j = 0; j < chicken.size(); j++) {
                if (isSelectedChicken[j] == true) {
                    int dist = abs(house[i].first - chicken[j].first)+ abs(house[i].second - chicken[j].second);
                    minDistance = minDistance > dist ? dist : minDistance;
                }
            }
            sumOfDistances += minDistance;
        }
        
        answer = answer > sumOfDistances ? sumOfDistances : answer;
        return;
    }


    if (chickenIndex == chicken.size()) {
        return;
    }
    isSelectedChicken[chickenIndex] = true;
    dfs(selectedChickenNum + 1, chickenIndex + 1);
    isSelectedChicken[chickenIndex] = false;

    // next index 
    dfs(selectedChickenNum, chickenIndex + 1);
}
int main() {
    cin >> N >> M;
    map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                house.push_back({i, j});
            } else if (map[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < 13; i++) {
        isSelectedChicken[i] = false;
    }

    dfs(0, 0);

    cout << answer << "\n";


}