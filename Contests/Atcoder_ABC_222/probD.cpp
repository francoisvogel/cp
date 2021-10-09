/*
 * File created on 10/09/2021 at 14:05:43.
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

const int siz = 3040;
const int MOD = 998244353;

int dp [siz][siz];

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < siz; i++) for (int j = 0; j < siz; j++) dp[i][j] = -1;

    int n;
    cin >> n;
    int lo [n];
    for (int i = 0; i < n; i++) cin >> lo[i];
    int hi [n];
    for (int i = 0; i < n; i++) cin >> hi[i];
    for (int i = 0; i < siz; i++) dp[n][i] = 1;
    for (int i = n-1; i >= 0; i--) {
        int ps = 0;
        for (int j = siz-1; j >= 0; j--) {
            if (lo[i] <= j && j <= hi[i]) {
                ps += dp[i+1][j];
                ps %= MOD;
            }
            dp[i][j] = ps;
        }
    }
    cout << dp[0][0];

    cout.flush();
    int d = 0;
    d++;
}