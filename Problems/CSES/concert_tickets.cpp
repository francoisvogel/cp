#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, nbRequests;
    cin >> n >> nbRequests;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        s.insert(-v);
    }

    for (int i = 0; i < nbRequests; i++) {
        int v;
        cin >> v;
        multiset<int>::iterator it = s.upper_bound(-v-1);
        if (it != s.end()) {
            cout << -(*it);
            s.erase(it);
        }
        else {
            cout << -1;
        }
        cout << endl;
    }

    int d = 0;
    d++;
}