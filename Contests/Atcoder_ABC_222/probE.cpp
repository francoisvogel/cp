/*
 * File created on 10/09/2021 at 14:14:37.
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

#define int ll
#define ll long long
#define ld long double

#pragma GCC optimization ("unroll-loops")

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int siz = 1040;
const int lim = 1e5+40;
const int MOD = 998244353;

vector<pii> graph [siz];
int on [siz];
int dp [lim];

bool dfs(int x, int p, int tar, vi& path) {
    if (x == tar) return true;
    for (pii y : graph[x]) if (y.f != p) {
        path.pb(y.s);
        if (dfs(y.f, x, tar, path)) {
            return true;
        }
        path.pop_back();
    }
    return false;
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, nbQ, kConst;
    cin >> n >> nbQ >> kConst;
    int q [nbQ];
    for (int i = 0; i < nbQ; i++) {
        cin >> q[i];
        q[i]--;
    }
    for (int i = 0; i < n-1; i++) {
        int na, nb;
        cin >> na >> nb;
        na--;
        nb--;
        graph[na].pb(pii(nb, i));
        graph[nb].pb(pii(na, i));
    }
    for (int i = 0; i < n; i++) on[i] = 0;
    for (int i = 0; i < nbQ-1; i++) {
        vi path;
        dfs(q[i], -1, q[i+1], path);
        for (int j : path) on[j]++;
    }
    int sum = 0;
    for (int i = 0; i < n-1; i++) sum += on[i];
    int aim = sum+kConst;
    if (aim < 0 || aim%2 == 1) {
        cout << 0;
        return 0;
    }
    aim /= 2LL;
    vi notZero;
    for (int i = 0; i < n-1; i++) if (on[i] != 0) notZero.pb(on[i]);
    for (int i = 0; i < lim; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i : notZero) {
        for (int j = lim-1; j >= i; j--) {
            dp[j] = (dp[j]+dp[j-i])%MOD;
        }
    }
    int res = dp[aim];
    int byP2 = n-1-size(notZero);
    for (int i = 0; i < byP2; i++) {
        res *= 2LL;
        res %= MOD;
    }
    cout << res;

    cout.flush();
    int d = 0;
    d++;
}