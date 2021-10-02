#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    int b [n];
    multiset<int> s;
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) s.insert(b[i]);
    for (int i = 0; i < n; i++) pos[b[i]].push_back(i);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (s.find(target-b[i]-b[j]) != s.end()) {
                int sug = pos[target-b[i]-b[j]][0];
                if (sug == i or sug == j) {
                    if (pos[target-b[i]-b[j]].size() > 1) {
                        sug = pos[target-b[i]-b[j]][1];
                        if (sug == i or sug == j) {
                            if (pos[target-b[i]-b[j]].size() > 2) {
                                sug = pos[target-b[i]-b[j]][2];
                            }
                            else continue;
                        }
                    }
                    else continue;
                }
                cout << i+1 << " " << j+1 << " " << sug+1;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";

    int d = 0;
    d++;
}