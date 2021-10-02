#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> s;

void rec(string left, string prefix) {
    if (left == "") {
        vector<int> vec(prefix.size());
        for (int i = 0;  i < vec.size(); i++) vec[i] = int(prefix[i])-48;
        s.push_back(vec);
    }
    else {
        for (int i = 0; i < left.size(); i++) {
            string newLeft = left.substr(0, i)+left.substr(i+1, left.size()-i-1);
            rec(newLeft, prefix+left[i]);
        }
    }
}

int main() {
    int n = 8;
    char b [n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> b[i][j];

    rec("01234567", "");
    
    int ways = 0;

    for (vector<int> prop : s) {
        bool ok = true;
        set<int> diagLeft;
        set<int> diagRight;
        for (int i = 0; i < n; i++) {
            diagLeft.insert(prop[i]-i);
            diagRight.insert(prop[i]+i);
            if (b[i][prop[i]] == '*' or diagLeft.size() <= i or diagRight.size() <= i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ways++;
        }
    }

    cout << ways;

    int d = 0;
    d++;
}