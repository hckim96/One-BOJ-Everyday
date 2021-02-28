#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printPreorder(vector<pair<char, char> >& arr, char root) {
    cout << root;

    if (arr[root - 'A'].first != '.') {
        printPreorder(arr, arr[root - 'A'].first);
    }
    if (arr[root - 'A'].second != '.') {
        printPreorder(arr, arr[root - 'A'].second);
    }
}
void printInorder(vector<pair<char, char> >& arr, char root) {

    if (arr[root - 'A'].first != '.') {
        printInorder(arr, arr[root - 'A'].first);
    }
    cout << root;
    if (arr[root - 'A'].second != '.') {
        printInorder(arr, arr[root - 'A'].second);
    }
}
void printPostorder(vector<pair<char, char> >& arr, char root) {

    if (arr[root - 'A'].first != '.') {
        printPostorder(arr, arr[root - 'A'].first);
    }
    if (arr[root - 'A'].second != '.') {
        printPostorder(arr, arr[root - 'A'].second);
    }
    cout << root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<pair<char, char> > arr(N);

    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        cin >> arr[c - 'A'].first >> arr[c - 'A'].second;
    }

    printPreorder(arr, 'A');
    cout << '\n';    
    printInorder(arr, 'A');
    cout << '\n';    
    printPostorder(arr, 'A');
    cout << '\n';
}