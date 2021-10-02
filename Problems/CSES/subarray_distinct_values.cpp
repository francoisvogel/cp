#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define ll long long

int main() {
    int n, maxDistinct;
    cin >> n >> maxDistinct;

    int b [n];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, int> m;
    ll counter = 0;
    int start = 0;
    int end = 0;
    while (start < n and end < n) {
        if (m.find(b[end]) != m.end() or m.size()+1 <= maxDistinct) {
            if (m.find(b[end]) == m.end()) m[b[end]] = 0;
            m[b[end]]++;
            end++;
            counter += (ll)(end-start);
        }
        else {
            m[b[start]]--;
            if (m[b[start]] == 0) m.erase(b[start]);
            start++;
        }
    }

    cout << counter;

    int d = 0;
    d++;
}