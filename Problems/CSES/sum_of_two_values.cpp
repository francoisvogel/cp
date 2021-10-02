#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    int tarDiv2Count = 0;
    vector<int> part;
    vector<int> veced;
    set<int> seted;
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        veced.push_back(v);
        seted.insert(v);
        if (v == target/2) {
            tarDiv2Count++;
            part.push_back(i+1);
        }
        pos[v] = i+1;
    }

    for (int i : veced) {
        if (seted.find(target-i) != seted.end() and target-i != i) {
            cout << pos[i] << " " << pos[target-i];
            return 0;
        }
    }

    if (tarDiv2Count >= 2 and target%2 == 0) {
        cout << part[0] << " " << part[1];
        return 0;
    }

    cout << "IMPOSSIBLE";

    int d = 0;
    d++;
}