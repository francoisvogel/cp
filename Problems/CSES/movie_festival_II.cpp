#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main() {
    int n, k;
    cin >> n >> k;
    
    pii b [n];
    for (int i = 0; i < n; i++) cin >> b[i].second >> b[i].first;
    sort(b, b+n);

    multiset<int> s;
    int counter = 0;
    for (pii i : b) {
        if (s.size() != 0 and s.upper_bound(i.second) != s.begin()) {
            s.erase(s.find(*(prev(s.upper_bound(i.second)))));
        }
        if (s.size() < k) {
            s.insert(i.first);
            counter++;
        }
    }

    cout << counter;

    int d = 0;
    d++;
}