#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (s.upper_bound(v) != s.end()) {
            s.erase(s.upper_bound(v));
        }
        s.insert(v);
    }

    cout << s.size();

    int d = 0;
    d++;
}