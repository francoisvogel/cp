#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll levelStart(int level) {
    
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        ll level = max(x, y);
        ll count;
        if (x <= y) {
            count = x;
        }
        else {
            count = level+level-y;
        }
        if (level%2 == 0) {
            count = levelStart(level+1)-levelStart(level)-1-count;
        }
        ll val = levelStart(level)+count;
        cout << val << endl;
    }

    int d = 0;
    d++;
}