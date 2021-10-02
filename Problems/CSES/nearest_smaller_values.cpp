#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main() {
    int n;
    cin >> n;

    vector<pii> q;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        vector<pii>::iterator it = upper_bound(q.begin(), q.end(), pii(v, -1));
        if (!q.empty() and it != q.begin()) {
            it = prev(it);
            cout << (*(it)).second+1;
        }
        else cout << 0;
        cout << " ";
        while (!q.empty() and q[q.size()-1].first >= v) q.pop_back();
        q.push_back(pii(v, i));
    }

    int d = 0;
    d++;    
}