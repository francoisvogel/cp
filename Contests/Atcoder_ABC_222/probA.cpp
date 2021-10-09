/*
 * File created on 10/09/2021 at 14:00:31.
 * Link to problem: 
 * Description: 
 * Time complexity: O()
 * Space complexity: O()
 * Status: DEV (most of the time I don't update status, so it stays DEV which is the default value)
 * Copyright: Ⓒ 2021 Francois Vogel
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
#define size(x) (int)(x.size())
#define pb push_back
#define ins insert
#define cls clear

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string b;
    cin >> b;
    while (size(b) < 4) {
        reverse(all(b));
        b += '0';
        reverse(all(b));
    }
    cout << b;

    cout.flush();
    int d = 0;
    d++;
}