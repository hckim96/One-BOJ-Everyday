#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
string allPossibleChars;
string vowels("aioue");
void dfs(int pos, string& string ,int vowel, int consonant) {
    if (pos == L) {
        if (vowel >= 1 && consonant >= 2) {
            cout << string << "\n";
        }
        return;
    }
    
    for (int i = allPossibleChars.find(string[pos - 1]) + 1; i < allPossibleChars.size(); i++) {
        if (vowels.find(allPossibleChars[i]) == string::npos) {
            consonant++;
        } else {
            vowel++;
        } 
        string.push_back(allPossibleChars[i]);
        dfs(pos + 1, string, vowel, consonant);
        string.pop_back();
        if (vowels.find(allPossibleChars[i]) == string::npos) {
            consonant--;
        } else {
            vowel--;
        } 
    }
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char tmp;
        cin >> tmp;
        allPossibleChars.push_back(tmp);
    }
    sort(allPossibleChars.begin(), allPossibleChars.end());
    string tmp;
    dfs(0, tmp, 0, 0);
}