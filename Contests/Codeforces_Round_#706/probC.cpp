/*
 * Author: Francois Vogel
 * Comment: 
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

#define pii pair<int, int>
#define f first
#define s second

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ins insert
#define cls clear

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void test() {
    int n;
    cin >> n;
    vi x, y;
    for (int i = 0; i < 2*n; i++) {
        int lx, ly;
        cin >> lx >> ly;
        if (lx == 0) y.pb(abs(ly));
        else x.pb(abs(lx));
    }
    sort(all(x));
    sort(all(y));
    ld sum = 0;
    for (int i = 0; i < n; i++) {
        ld a = x[i];
        ld b = y[i];
        sum += sqrtl(a*a+b*b);
    }
    cout.precision(17);
    cout << sum << endl;
}

signed main() {
    cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) test();

    int d = 0;
    d++;
}