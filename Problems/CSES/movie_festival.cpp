#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main() {
    int n;
    cin >> n;

    vector<pii> b(n);
    for (int i = 0; i < n; i++) cin >> b[i].second >> b[i].first;

    sort(b.begin(), b.end());

    int latestEnd = -1;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (b[i].second >= latestEnd) {
            counter++;
            latestEnd = b[i].first;
        }
    }

    cout << counter;

    int d = 0;
    d++;
}