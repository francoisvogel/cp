/*
 * File created on 10/17/2021 at 12:39:34.
 * Link to problem: 
 * Description: 
 * Time complexity: O()
 * Space complexity: O()
 * Status: ---
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
#define size(x) (int)((x).size())
#define pb push_back
#define ins insert
#define cls clear

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int siz = 100*200+40;

bool prime [siz];

void solve() {
    int n;
    cin >> n;
    int b [n];
    for (int i = 0; i < n; i++) cin >> b[i];
    int sum = 0;
    for (int i = 0; i < n; i++) sum += b[i];
    if (!prime[sum]) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) if (!prime[sum-b[i]]) {
        cout << n-1 << '\n';
        for (int j = 0; j < n; j++) if (j != i) cout << j+1 << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) if (!prime[sum-b[i]-b[j]]) {
        cout << n-2;
        cout << '\n';
        for (int k = 0; k < n; k++) if (k != i && k != j) cout << k+1 << ' ';
        cout << '\n';
        return;
    }
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < siz; i++) prime[i] = true;
    for (int i = 2; i < siz; i++) if (prime[i]) {
        for (int j = 2*i; j < siz; j += i) prime[j] = false;
    }

    int n;
    cin >> n;
    while (n--) solve();

    cout.flush();
    int d = 0;
    d++;
}