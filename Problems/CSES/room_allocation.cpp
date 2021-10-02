#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define mp pair<pii, int>
#define pii pair<int, int>

int main() {
    int n;
    cin >> n;

    mp b [n];
    for (int i = 0; i < n; i++) cin >> b[i].first.first >> b[i].first.second;
    for (int i = 0; i < n; i++) b[i].second = i;

    sort(b, b+n);

    multiset<pii> s;
    int sCounter = 1;
    int ass [n];
    for (int i = 0; i < n; i++) {
        if (!s.empty() and (*(s.begin())).first < b[i].first.first) { // not sur about <= or <
            s.insert(pii(b[i].first.second, (*(s.begin())).second));
            ass[b[i].second] = (*(s.begin())).second;
            s.erase(s.begin());
        }
        else {
            s.insert(pii(b[i].first.second, sCounter));
            ass[b[i].second] = sCounter;
            sCounter++;
        }
    }

    cout << s.size() << endl;
    for (int i = 0; i < n; i++) cout << ass[i] << " ";

    int d = 0;
    d++;
}