#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++)z cin >> b[i];

    int limit = 1;
    for (int i = 0; i < n; i++) limit *= 2;

    ll minDif = 1000000000000LL;

    for (int i = 0; i < limit; i++) {
        bitset<20> bit(i);
        ll s1 = 0;
        ll s2 = 0;
        for (int j = 0; j < n; j++) {
            if (bit[j]) s1 += b[j];
            else s2 += b[j];
        }
        minDif = min(minDif, max(s1-s2, s2-s1));
    }

    cout << minDif;

    int d = 0;
    d++;
}