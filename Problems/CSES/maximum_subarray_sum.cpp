#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    ll b [n];
    ll biggest = -1000000000000LL;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        biggest = max(biggest, b[i]);
    }

    ll kadane [n];
    ll maxv = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) kadane[i] = kadane[i-1];
        else kadane[i] = 0LL;
        kadane[i] += b[i];
        kadane[i] = max(kadane[i], 0LL);
        maxv = max(maxv, kadane[i]);
    }

    if (biggest < 0) maxv = min(maxv, biggest);

    cout << maxv;

    int d = 0;
    d++;
}