#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int b [n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int start = 0;
    int end = 0;
    int maxv = 0;
    set<int> s;
    while (start < n and end < n) {
        if (s.find(b[end]) == s.end()) {
            s.insert(b[end]);
            end++;
            maxv = max(maxv, end-start);
        }
        else {
            s.erase(s.find(b[start]));
            start++;
        }
    }

    cout << maxv;

    int d = 0;
    d++;
}