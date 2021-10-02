#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main() {
    int n;
    cin >> n;
    vector<pii> b;
    for (int i = 0; i < n; i++) {
        int ta, tb;
        cin >> ta >> tb;
        b.push_back(pii(ta, 1));
        b.push_back(pii(tb, -1));
    }
    sort(b.begin(), b.end());
    int counter = 0;
    int maxv = 0;
    for (pii i : b) {
        counter += i.second;
        maxv = max(maxv, counter);
    }
    cout << maxv;
    int d = 0;
    d++;
}