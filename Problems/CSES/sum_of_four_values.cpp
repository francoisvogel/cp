#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main() {
    int n, target;
    cin >> n >> target;

    int b [n];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, vector<pii>> pairWithVal;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            pairWithVal[b[i]+b[j]].push_back(pii(i, j));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (pii k : pairWithVal[target-b[i]-b[j]]) {
                if (k.first != i and k.second != j and k.first != j and k.second != i) {
                    cout << i+1 << " " << j+1 << " " << k.first+1 << " " << k.second+1;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";

    int d = 0;
    d++;
}