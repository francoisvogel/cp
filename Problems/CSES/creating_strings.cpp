#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> s;

void rec(string left, string prefix) {
    if (left == "") {
        s.insert(prefix);
    }
    else {
        for (int i = 0; i < left.size(); i++) {
            string newLeft = left.substr(0, i)+left.substr(i+1, left.size()-i-1);
            rec(newLeft, prefix+left[i]);
        }
    }
}

int main() {
    string str;
    cin >> str;

    rec(str, "");
    
    cout << s.size() << endl;
    for (string i : s) cout << i << endl;

    int d = 0;
    d++;
}