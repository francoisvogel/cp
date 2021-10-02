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
// #define s second

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ins insert
#define cls clear

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void test() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool same = true;
    for (int i = 0; i < k; i++) {
        if (s[i] != s[n-1-i]) same = false;
    }
    if (same and 2*k != n) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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