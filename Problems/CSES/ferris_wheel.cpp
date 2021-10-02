#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, maxTolerance;
    cin >> n >> maxTolerance;

    vector<int> b;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        b.push_back(v);
        s.insert(-v);
    }

    int gondolas = 0;
    for (int i : b) {
        if (s.find(-i) != s.end()) {
            s.erase(s.find(-i));
            multiset<int>::iterator it = s.upper_bound(-(maxTolerance-i)-1);
            if (it != s.end()) s.erase(it);
            gondolas++;
        }
    }

    cout << gondolas;

    int d = 0;
    d++;
}