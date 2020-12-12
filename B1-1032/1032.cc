#include <iostream>
#include <string>

using namespace std;

int main() {

  int N;
  string answer;
  string inputString;
  cin >> N;

  cin >> answer;
  for (int i = 1; i < N; i++) {
    cin >> inputString;
    for (int j = 0; j < answer.length(); j++) {
      if (answer[j] == '?') {
        continue;
      } else if (answer[j] != inputString[j]) {
        answer[j] = '?';
      }
    }
  }
  cout << answer << endl;

}